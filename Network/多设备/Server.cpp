//Server.cpp
#include "DES_s.h"
#pragma comment(lib, "ws2_32.lib")
using std::string;
using std::vector;

constexpr uint16_t DEFAULT_PORT = 5000;
constexpr size_t   BUFFER_SIZE = 1024;

std::mutex gMutex;
std::unordered_map<SOCKET, string> sock2user;
std::unordered_map<string, SOCKET> user2sock;
std::unordered_map<string, vector<SOCKET>> groups;
std::unordered_map<string, string> groupOwners; // �������鴴���ߵ�ӳ��
std::unordered_map<std::string, std::unordered_set<std::string>> mutedUsers;
std::mutex logMutex;  // ��־�ļ�������

std::string bytesToHex(const char* data, size_t len) {
    std::string hex;
    hex.reserve(len * 2);
    static const char* digits = "0123456789ABCDEF";
    for (size_t i = 0; i < len; ++i) {
        unsigned char c = static_cast<unsigned char>(data[i]);
        hex += digits[c >> 4];
        hex += digits[c & 0x0F];
        hex += ' ';
    }
    if (!hex.empty()) hex.pop_back(); // ȥ�����һ���ո�
    return hex;
}

static void logEvent(const std::string& type, const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    FILE* logFile = nullptr;
    fopen_s(&logFile, "server.log", "a");
    if (logFile) {
        // ��ȡ��ǰʱ��
        time_t now = time(nullptr);
        struct tm tmBuf;
        localtime_s(&tmBuf, &now);
        char timeStr[64];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &tmBuf);

        // д����־�ļ�
        fprintf(logFile, "[%s][%s] %s\n", timeStr, type.c_str(), message.c_str());
        fclose(logFile);
    }
}

void safeSend(SOCKET s, const std::string& msg) {
    //// PKCS#7���
    //size_t pad = 8 - (msg.size() % 8);
    //std::string padded = msg + std::string(pad, static_cast<char>(pad));

    //// DES����
    //std::vector<char> encrypted;
    //for (size_t i = 0; i < padded.size(); i += 8) {
    //    char block[8];
    //    memcpy(block, padded.c_str() + i, 8);
    //    des_encrypt(block);
    //    encrypted.insert(encrypted.end(), block, block + 8);
    //}

    //// ���ͼ�������
    //int ret = send(s, encrypted.data(), encrypted.size(), 0);
    //if (ret == SOCKET_ERROR) {
    //    fprintf(stderr, "[!] send() error %d on socket %llu\n",
    //        WSAGetLastError(), static_cast<unsigned long long>(s));
    //}

    // --- 1. PKCS#7 ��� ---
    logEvent("SEND_PLAIN", "[" + std::to_string(s) + "] " + msg);
    size_t pad = 8 - (msg.size() % 8);
    if (pad == 0) pad = 8;
    std::string padded = msg + std::string(pad, static_cast<char>(pad));

    // --- 2. ���� ---
    std::vector<char> enc;
    enc.reserve(padded.size());
    for (size_t i = 0; i < padded.size(); i += 8) {
        char blk[8]; memcpy(blk, padded.data() + i, 8);
        des_encrypt(blk);
        enc.insert(enc.end(), blk, blk + 8);
    }
    // ��ӡ���ܺ���ֽ���
    /*std::cout << "[���ܺ����Ϣ]: ";
    for (char c : enc) {
        std::cout << std::hex << (0xFF & c) << " ";
    }
    std::cout << std::endl;*/

    logEvent("SEND_ENCRYPTED", "[" + std::to_string(s) + "] " + bytesToHex(enc.data(), enc.size()));

    // --- 3. �� 4 �ֽڳ���ͷ���� ---
    uint32_t L = htonl(static_cast<uint32_t>(msg.size()));  // ���ĳ���
    send(s, reinterpret_cast<char*>(&L), 4, 0);
    send(s, enc.data(), static_cast<int>(enc.size()), 0);
}

void pruneDeadSocket(SOCKET deadSock) {
    std::string username;
    {
        std::lock_guard<std::mutex> lock(gMutex);
        auto it = sock2user.find(deadSock);
        if (it != sock2user.end()) {
            username = it->second;
        }
        else {
            return; // ��������ֱ������
        }
    }


    // �������Ա
    for (auto it = groups.begin(); it != groups.end();) {
        auto& vec = it->second;
        vec.erase(std::remove(vec.begin(), vec.end(), deadSock), vec.end());

        // �����Ϊ�գ����Ƴ�����
        if (vec.empty()) {
            groupOwners.erase(it->first); // �Ƴ�����������Ϣ
            it = groups.erase(it);
        }
        else {
            ++it;
        }
    }
}

// �������ˣ��������ͻ������ӣ�֧����ʽ����ͷ + DES ���ܣ���������������жϿ���
void handleClient(SOCKET clientSock, sockaddr_in addr)
{
    std::vector<char> inBuf;                  // ԭʼ���ջ���
    std::vector<char> plainBuf;               // ���ܺ�����
    char ipStr[INET_ADDRSTRLEN]{};
    char tmp[BUFFER_SIZE];

    // ȡ�ÿͻ��� IP �ַ���
    if (inet_ntop(AF_INET, &addr.sin_addr, ipStr, INET_ADDRSTRLEN) == nullptr) {
        perror("inet_ntop error");
        return;
    }
    std::string clientIP(ipStr);

    logEvent("CONNECT", "Socket:" + std::to_string(clientSock) + " IP:" + clientIP);

    // ----------------------- ��ʼ��Ĭ���û��� -----------------------
    {
        std::lock_guard<std::mutex> lock(gMutex);
        std::string defName = "Guest_" + clientIP + "_" + std::to_string(clientSock);
        sock2user[clientSock] = defName;
        user2sock[defName] = clientSock;
    }
    printf("[+] %s connected (%llu)\n", clientIP.c_str(),
        static_cast<unsigned long long>(clientSock));

    // ----------------------- �հ����� lambda -----------------------
    auto needMore = [&](void) -> bool {
        int n = recv(clientSock, tmp, BUFFER_SIZE, 0);
        if (n <= 0) {
            return false;                     // �Զ˹رջ����
        }
        inBuf.insert(inBuf.end(), tmp, tmp + n);
        return true;
        };

    // ======================= ��ѭ����������ȡ =======================
    std::string type, target, extra;
    while (true)
    {
        /*----------- �� ��ȷ���� 4 �ֽڳ���ͷ -----------*/
        while (inBuf.size() < 4 && needMore()) {}
        if (inBuf.size() < 4) break;          // ���ӶϿ�

        uint32_t L;
        memcpy(&L, inBuf.data(), 4);
        L = ntohl(L);                         // ���ĳ���

        /*----------- �� �������ĳ��ȣ�����䣩-----------*/
        size_t pad = 8 - (L % 8);
        if (pad == 0) pad = 8;
        size_t encLen = L + pad;

        /*----------- �� ������������ -----------*/
        while (inBuf.size() < 4 + encLen && needMore()) {}
        if (inBuf.size() < 4 + encLen) break; // ���ӶϿ�

        /*----------- �� ���� -----------*/
        plainBuf.clear();
        for (size_t off = 4; off < 4 + encLen; off += 8) {
            char blk[8];
            memcpy(blk, inBuf.data() + off, 8);
            des_decrypt(blk);
            plainBuf.insert(plainBuf.end(), blk, blk + 8);
        }
        inBuf.erase(inBuf.begin(), inBuf.begin() + 4 + encLen);  // �Ƴ��Ѵ���

        /*----------- �� ȥ�� PKCS#7 ��� -----------*/
        if (plainBuf.empty()) continue;
        size_t realLen = plainBuf.size() -
            static_cast<unsigned char>(plainBuf.back());
        if (realLen > plainBuf.size()) continue;  // ������쳣�����Դ˰�
        std::string decrypted(plainBuf.data(), realLen);
		
        // ��ӡ���ܺ���ֽ���
        logEvent("RECV_DECRYPTED", "[" + std::to_string(clientSock) + "] " + decrypted);

        /*----------- �� ����Э�� TYPE|TARGET|BODY -----------*/
        size_t p1 = decrypted.find('|');
        size_t p2 = decrypted.find('|', p1 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        std::string type = decrypted.substr(0, p1);
        std::string target = decrypted.substr(p1 + 1, p2 - p1 - 1);
        std::string body = decrypted.substr(p2 + 1);

        // ��ȫ��־�����������Ϣ����
        /*printf("[DEBUG] �յ�Э�飺Type=%s | Target=%s | BodyLength=%zu �ֽ�\n",
            type.c_str(), target.c_str(), body.size());*/
        // ====================== ������ ԭҵ���߼����� ������ ======================
        if (type == "LOGIN") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (user2sock.count(target)) {
                safeSend(clientSock, "SYS|-|�û����ѱ�ʹ�ã���ѡ����������");
                continue;
            }
            std::string old = sock2user[clientSock];
            user2sock.erase(old);
            sock2user[clientSock] = target;
            user2sock[target] = clientSock;
            safeSend(clientSock, "LOGIN|-|" + target);

            logEvent("USER_LOGIN", "[" + std::to_string(clientSock) + "] " + target);
        }
        else if (type == "CREATE") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (groups.count(target)) {
                safeSend(clientSock, "SYS|-|Ⱥ�����Ѵ��ڣ���ѡ����������");
                continue;
            }
            groups[target].push_back(clientSock);
            groupOwners[target] = sock2user[clientSock];
            printf("[*] �û� %s ������Ⱥ�� %s\n",
                sock2user[clientSock].c_str(), target.c_str());
            safeSend(clientSock, "CREATE|-|" + target);

            logEvent("GROUP_CREATE", "Group:" + target + " Owner:" + sock2user[clientSock]);
        }
        // KICK ��������޸�
        else if (type == "KICK") {
            std::string username;
            {
                std::lock_guard<std::mutex> lock(gMutex);
                auto it = sock2user.find(clientSock);
                if (it != sock2user.end()) {
                    username = it->second;
                }
                else {
                    safeSend(clientSock, "SYS|-|��ݴ�������������");
                    break;
                }
            }

            // �� body �л�ȡҪ�߳����û���
            std::string kickUser = body;  // body �а���Ҫ�߳����û���

            std::lock_guard<std::mutex> lock(gMutex);
            if (groupOwners[target] != username) {
                safeSend(clientSock, "SYS|-|������Ⱥ�����޷�ִ�����˲���");
            }
            else if (user2sock.find(kickUser) == user2sock.end()) {
                safeSend(clientSock, "SYS|-|�û�������");
            }
            else {
                SOCKET targetSock = user2sock[kickUser];
                auto& vec = groups[target];
                auto it = std::find(vec.begin(), vec.end(), targetSock);
                if (it != vec.end()) {
                    vec.erase(it);
                    // ������û��ڽ����б��У�Ҳһ���Ƴ�
                    if (mutedUsers.count(target)) {
                        mutedUsers[target].erase(kickUser);
                    }
                    safeSend(targetSock, "SYS|-|���ѱ��߳�Ⱥ�� " + target);
                    safeSend(clientSock, "SYS|-|�ѽ� " + kickUser + " �߳�Ⱥ�� " + target);
                    for (SOCKET s : vec) {
                        if (s != clientSock)
                            safeSend(s, "SYS|-|�û� " + kickUser + " ���˳�Ⱥ�� " + target);
                    }
                }
                else {
                    safeSend(clientSock, "SYS|-|���û�����Ⱥ����");
                }
            }
        }
        else if (type == "DISBAND") {
            std::string username;
            {
                std::lock_guard<std::mutex> lock(gMutex);
                auto it = sock2user.find(clientSock);
                if (it != sock2user.end()) {
                    username = it->second;
                }
                else {
                    safeSend(clientSock, "SYS|-|��ݴ�������������");
                    break;
                }
            }

            std::lock_guard<std::mutex> lock(gMutex);
            if (groupOwners[target] != username) {
                safeSend(clientSock, "SYS|-|�㲻��Ⱥ�����޷���ɢȺ��");
            }
            else {
                auto vec = groups[target];
                for (SOCKET s : vec) {
                    if (s != clientSock)
                        safeSend(s, "SYS|-|Ⱥ�� " + target + " �ѱ�Ⱥ����ɢ");
                }
                groups.erase(target);
                groupOwners.erase(target);
                safeSend(clientSock, "SYS|-|���ѽ�ɢȺ�� " + target);
            }
        }
        else if (type == "MUTE") {
            std::lock_guard<std::mutex> lock(gMutex);
            std::string operatorName = sock2user[clientSock];

            if (groupOwners[target] != operatorName) {
                safeSend(clientSock, "SYS|-|������Ⱥ����û��Ȩ�޽���Ⱥ��Ա");
            }
            else {
                // ���Ŀ���û��Ƿ���Ⱥ����
                bool inGroup = false;
                auto& members = groups[target];
                for (SOCKET s : members) {
                    if (sock2user[s] == body) {
                        inGroup = true;
                        break;
                    }
                }
                if (!inGroup) {
                    safeSend(clientSock, "SYS|-|�û�����Ⱥ�ڣ��޷�����");
                }
                else {
                    if (user2sock.find(body) == user2sock.end() ||
                        std::find(groups[target].begin(), groups[target].end(), user2sock[body]) == groups[target].end()) {
                        safeSend(clientSock, "SYS|-|���û�����Ⱥ����");
                    }
                    else {
                        mutedUsers[target].insert(body);
                        safeSend(clientSock, "SYS|-|�ѽ� " + body + " ����");
                    }
                }

            }
            }
        else if (type == "UNMUTE") {
            std::lock_guard<std::mutex> lock(gMutex);
            std::string operatorName = sock2user[clientSock];

            if (groupOwners[target] != operatorName) {
                safeSend(clientSock, "SYS|-|�㲻��Ⱥ�����޷��������");
            }
            else if (user2sock.find(body) == user2sock.end() ||
                std::find(groups[target].begin(), groups[target].end(), user2sock[body]) == groups[target].end()) {
                safeSend(clientSock, "SYS|-|���û�����Ⱥ����");
            }
            else if (!mutedUsers.count(target) || mutedUsers[target].count(body) == 0) {
                safeSend(clientSock, "SYS|-|���û�δ�����ԣ��޷����");
            }
            else {
                mutedUsers[target].erase(body);
                safeSend(clientSock, "SYS|-|�ѽ� " + body + " �������");
            }
        }
        else if (type == "PRIVATE") {
            SOCKET dst;
            {
                std::lock_guard<std::mutex> lock(gMutex);
                if (!user2sock.count(target)) {
                    safeSend(clientSock, "SYS|-|�û������ڻ�������");
                    continue;
                }
                dst = user2sock[target];
            }
            std::string sender;
            {
                std::lock_guard<std::mutex> lock(gMutex);
                sender = sock2user[clientSock];
            }
            safeSend(dst, "PRIVATE|" + sender + "|" + body);

            logEvent("PRIVATE_MSG", "From:" + sender + " To:" + target + " Len:" + std::to_string(body.size()));
        }
        else if (type == "PUBLIC") {
            std::vector<SOCKET> rec;
            std::string sender;
            {
                std::lock_guard<std::mutex> lock(gMutex);
                sender = sock2user[clientSock];
                for (auto& kv : sock2user) rec.push_back(kv.first);
            }
            for (SOCKET s : rec)
                if (s != clientSock)
                    safeSend(s, "PUBLIC|" + sender + "|" + body);
			logEvent("PUBLIC_MSG", "From:" + sender + " Len:" + std::to_string(body.size()));
        }
        else if (type == "JOIN") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (!groups.count(target)) {
                safeSend(clientSock, "SYS|-|Ⱥ�鲻���ڣ����ȴ�����������");
                continue;
            }
            auto& members = groups[target];
            if (std::find(members.begin(), members.end(), clientSock) != members.end()) {
                safeSend(clientSock, "SYS|-|���Ѿ��ڸ�Ⱥ����");
                continue;
            }
            members.push_back(clientSock);
            std::string username = sock2user[clientSock];
            printf("[*] �û� %s ������Ⱥ�� %s\n", username.c_str(), target.c_str());
            safeSend(clientSock, "JOIN|-|" + target);
            for (SOCKET s : members)
                if (s != clientSock)
                    safeSend(s, "SYS|-|�û� " + username + " ������Ⱥ�� " + target);
			logEvent("GROUP_JOIN", "Group:" + target + " User:" + username);
        }
        else if (type == "LEAVE") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (!groups.count(target)) {
                safeSend(clientSock, "SYS|-|Ⱥ�鲻����");
                continue;
            }
            auto& vec = groups[target];
            auto  itMember = std::find(vec.begin(), vec.end(), clientSock);
            if (itMember == vec.end()) {
                safeSend(clientSock, "SYS|-|�����ڸ�Ⱥ����");
                continue;
            }

            std::string username = sock2user[clientSock];
            vec.erase(itMember);

            // Ⱥ��ת��
            if (groupOwners[target] == username && !vec.empty()) {
                SOCKET newSock = vec.front();
                std::string newBoss = sock2user[newSock];
                groupOwners[target] = newBoss;
                safeSend(newSock, "SYS|-|���ѳ�ΪȺ�� " + target + " ���¹���Ա");
                for (SOCKET s : vec)
                    if (s != newSock)
                        safeSend(s, "SYS|-|�û� " + newBoss + " �ѳ�ΪȺ�� "
                            + target + " ���¹���Ա");
            }

            if (vec.empty()) {
                groups.erase(target);
                groupOwners.erase(target);
                printf("[*] Ⱥ�� %s �ѱ�ɾ��\n", target.c_str());
            }

            safeSend(clientSock, "LEAVE|-|" + target);
            // ��Ⱥ��������Ա�㲥�û��˳�
            for (SOCKET s : vec) {
                if (s != clientSock) {
                    safeSend(s, "SYS|-|�û� " + username + " ���˳�Ⱥ�� " + target);
                }
            }

			logEvent("GROUP_LEAVE", "Group:" + target + " User:" + username);
        }
        else if (type == "MEMBERS") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (groups.find(target) == groups.end()) {
                safeSend(clientSock, "SYS|-|Ⱥ�鲻����");
            }
            else {
                std::string list = "SYS|-|Ⱥ���Ա��";
                for (SOCKET s : groups[target]) {
                    list += sock2user[s] + " ";
                }
                safeSend(clientSock, list);
            }
        }
        else if (type == "GROUP") {
            std::string sender = sock2user[clientSock];
            std::lock_guard<std::mutex> lock(gMutex);

            // ���Ⱥ�Ƿ����
            if (!groups.count(target)) {
                safeSend(clientSock, "SYS|-|Ⱥ�鲻����");
                continue;
            }

            // ����Ƿ�����Ⱥ��
            auto& members = groups[target];
            if (std::find(members.begin(), members.end(), clientSock) == members.end()) {
                safeSend(clientSock, "SYS|-|���Ѳ��ڸ�Ⱥ���У��޷�����");
                continue;
            }


            // ����Ƿ񱻽���
            if (mutedUsers[target].count(sender)) {
                safeSend(clientSock, "SYS|-|���ѱ�Ⱥ�����ԣ��޷�����");
                continue;
            }

            for (SOCKET s : groups[target]) {
                if (s != clientSock) {
                    safeSend(s, "GROUP|" + target + "|" + sender + "|" + body);
                }
            }

            logEvent("GROUP_MSG", "Group:" + target + " From:" + sender + " Len:" + std::to_string(body.size()));
        }
        else if (type == "MUTED") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (!groups.count(target)) {
                safeSend(clientSock, "SYS|-|Ⱥ�鲻����");
                continue;
            }

            const auto& groupMembers = groups[target];
            if (std::find(groupMembers.begin(), groupMembers.end(), clientSock) == groupMembers.end()) {
                safeSend(clientSock, "SYS|-|�����ڸ�Ⱥ���У��޷��鿴�����б�");
                continue;
            }

            std::string list;
            for (const auto& name : mutedUsers[target]) {
                list += name + "\n";
            }
            if (list.empty()) list = "(�޽��Գ�Ա)";

            safeSend(clientSock, "MUTED|" + target + "|" + list);
			logEvent("GROUP_MUTED_LIST", "Group:" + target + " User:" + sock2user[clientSock]);
        }
        else if (type == "LIST") {
            if (target == "USERS") {
                std::lock_guard<std::mutex> lock(gMutex);
                std::string list;
                for (auto& kv : user2sock) list += kv.first + ",";
                if (!list.empty()) list.pop_back();
                safeSend(clientSock, "USERS|-|" + list);
            }
            else if (target == "GROUPS") {
                std::lock_guard<std::mutex> lock(gMutex);
                std::string list;
                for (auto& kv : groups) {
                    list += kv.first;
                    if (groupOwners.count(kv.first))
                        list += " (Ⱥ��: " + groupOwners[kv.first] + ")";
                    list += ",";
                }
                if (!list.empty()) list.pop_back();
                safeSend(clientSock, "GROUPS|-|" + list);
            }
        }
        // ====================== ������ ҵ���߼����� ������ ======================
    }


    std::string username = sock2user[clientSock];
    logEvent("DISCONNECT", "User:" + username + " IP:" + clientIP + " Socket:" + std::to_string(clientSock));
    /*------------- ���������û���Ϣ -------------*/
    {
        std::lock_guard<std::mutex> lock(gMutex);
        auto it = sock2user.find(clientSock);
        if (it != sock2user.end()) {
            std::string name = it->second;
            sock2user.erase(it);
            user2sock.erase(name);
        }
    }
    pruneDeadSocket(clientSock);

    printf("[-] %s disconnected (%llu)\n", clientIP.c_str(),
        static_cast<unsigned long long>(clientSock));
    shutdown(clientSock, SD_BOTH);
    closesocket(clientSock);
}

int main() {
    logEvent("SERVER", "=== Server Started ===");
    try {
        // ��ʼ��DES����
        if (des_init(0) == 0) {
            fprintf(stderr, "DES��ʼ��ʧ��\n");
            return 1;
        }
        des_set_key((char*)"mykey12"); // ������ͻ�����Կһ��

        WSADATA ws;
        if (WSAStartup(MAKEWORD(2, 2), &ws)) {
            des_done();
            return fprintf(stderr, "WSAStartup error\n"), 1;
        }

        SOCKET srv = socket(AF_INET, SOCK_STREAM, 0);
        if (srv == INVALID_SOCKET) {
            des_done();
            WSACleanup();
            return fprintf(stderr, "socket() error %d\n", WSAGetLastError()), 1;
        }

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(DEFAULT_PORT);
        if (bind(srv, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
            des_done();
            closesocket(srv);
            WSACleanup();
            return fprintf(stderr, "bind() error %d\n", WSAGetLastError()), 1;
        }

        if (listen(srv, SOMAXCONN) == SOCKET_ERROR) {
            des_done();
            closesocket(srv);
            WSACleanup();
            return fprintf(stderr, "listen() error %d\n", WSAGetLastError()), 1;
        }

        printf("[*] ��ȫ��������������� (DES����������) �˿�: %d...\n", DEFAULT_PORT);

        while (true) {
            sockaddr_in cliAddr{};
            int len = sizeof(cliAddr);
            SOCKET cli = accept(srv, (sockaddr*)&cliAddr, &len);
            if (cli == INVALID_SOCKET) {
                fprintf(stderr, "accept() error %d\n", WSAGetLastError());
                continue;
            }
            std::thread(handleClient, cli, cliAddr).detach();
        }

        // ������Դ�������ϲ���ִ�е����
        des_done();
        closesocket(srv);
        WSACleanup();
    }
    catch (const std::exception& e) {
        des_done();
        WSACleanup();

        logEvent("SERVER", "!!! Server Crashed !!!");
        fprintf(stderr, "�������쳣��ֹ: %s\n", e.what());
    }
    logEvent("SERVER", "=== Server Stopped ===");
    return 0;
}
