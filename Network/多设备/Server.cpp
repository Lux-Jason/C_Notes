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
std::unordered_map<string, string> groupOwners; // 添加组和组创建者的映射
std::unordered_map<std::string, std::unordered_set<std::string>> mutedUsers;
std::mutex logMutex;  // 日志文件互斥锁

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
    if (!hex.empty()) hex.pop_back(); // 去掉最后一个空格
    return hex;
}

static void logEvent(const std::string& type, const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    FILE* logFile = nullptr;
    fopen_s(&logFile, "server.log", "a");
    if (logFile) {
        // 获取当前时间
        time_t now = time(nullptr);
        struct tm tmBuf;
        localtime_s(&tmBuf, &now);
        char timeStr[64];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &tmBuf);

        // 写入日志文件
        fprintf(logFile, "[%s][%s] %s\n", timeStr, type.c_str(), message.c_str());
        fclose(logFile);
    }
}

void safeSend(SOCKET s, const std::string& msg) {
    //// PKCS#7填充
    //size_t pad = 8 - (msg.size() % 8);
    //std::string padded = msg + std::string(pad, static_cast<char>(pad));

    //// DES加密
    //std::vector<char> encrypted;
    //for (size_t i = 0; i < padded.size(); i += 8) {
    //    char block[8];
    //    memcpy(block, padded.c_str() + i, 8);
    //    des_encrypt(block);
    //    encrypted.insert(encrypted.end(), block, block + 8);
    //}

    //// 发送加密数据
    //int ret = send(s, encrypted.data(), encrypted.size(), 0);
    //if (ret == SOCKET_ERROR) {
    //    fprintf(stderr, "[!] send() error %d on socket %llu\n",
    //        WSAGetLastError(), static_cast<unsigned long long>(s));
    //}

    // --- 1. PKCS#7 填充 ---
    logEvent("SEND_PLAIN", "[" + std::to_string(s) + "] " + msg);
    size_t pad = 8 - (msg.size() % 8);
    if (pad == 0) pad = 8;
    std::string padded = msg + std::string(pad, static_cast<char>(pad));

    // --- 2. 加密 ---
    std::vector<char> enc;
    enc.reserve(padded.size());
    for (size_t i = 0; i < padded.size(); i += 8) {
        char blk[8]; memcpy(blk, padded.data() + i, 8);
        des_encrypt(blk);
        enc.insert(enc.end(), blk, blk + 8);
    }
    // 打印加密后的字节流
    /*std::cout << "[加密后的消息]: ";
    for (char c : enc) {
        std::cout << std::hex << (0xFF & c) << " ";
    }
    std::cout << std::endl;*/

    logEvent("SEND_ENCRYPTED", "[" + std::to_string(s) + "] " + bytesToHex(enc.data(), enc.size()));

    // --- 3. 带 4 字节长度头发送 ---
    uint32_t L = htonl(static_cast<uint32_t>(msg.size()));  // 明文长度
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
            return; // 不存在则直接跳出
        }
    }


    // 清理组成员
    for (auto it = groups.begin(); it != groups.end();) {
        auto& vec = it->second;
        vec.erase(std::remove(vec.begin(), vec.end(), deadSock), vec.end());

        // 如果组为空，则移除该组
        if (vec.empty()) {
            groupOwners.erase(it->first); // 移除组所有者信息
            it = groups.erase(it);
        }
        else {
            ++it;
        }
    }
}

// 服务器端：处理单个客户端连接（支持显式长度头 + DES 解密，不会再因填充误判断开）
void handleClient(SOCKET clientSock, sockaddr_in addr)
{
    std::vector<char> inBuf;                  // 原始接收缓冲
    std::vector<char> plainBuf;               // 解密后明文
    char ipStr[INET_ADDRSTRLEN]{};
    char tmp[BUFFER_SIZE];

    // 取得客户端 IP 字符串
    if (inet_ntop(AF_INET, &addr.sin_addr, ipStr, INET_ADDRSTRLEN) == nullptr) {
        perror("inet_ntop error");
        return;
    }
    std::string clientIP(ipStr);

    logEvent("CONNECT", "Socket:" + std::to_string(clientSock) + " IP:" + clientIP);

    // ----------------------- 初始化默认用户名 -----------------------
    {
        std::lock_guard<std::mutex> lock(gMutex);
        std::string defName = "Guest_" + clientIP + "_" + std::to_string(clientSock);
        sock2user[clientSock] = defName;
        user2sock[defName] = clientSock;
    }
    printf("[+] %s connected (%llu)\n", clientIP.c_str(),
        static_cast<unsigned long long>(clientSock));

    // ----------------------- 收包辅助 lambda -----------------------
    auto needMore = [&](void) -> bool {
        int n = recv(clientSock, tmp, BUFFER_SIZE, 0);
        if (n <= 0) {
            return false;                     // 对端关闭或错误
        }
        inBuf.insert(inBuf.end(), tmp, tmp + n);
        return true;
        };

    // ======================= 主循环：按包读取 =======================
    std::string type, target, extra;
    while (true)
    {
        /*----------- ① 先确保有 4 字节长度头 -----------*/
        while (inBuf.size() < 4 && needMore()) {}
        if (inBuf.size() < 4) break;          // 连接断开

        uint32_t L;
        memcpy(&L, inBuf.data(), 4);
        L = ntohl(L);                         // 明文长度

        /*----------- ② 计算密文长度（含填充）-----------*/
        size_t pad = 8 - (L % 8);
        if (pad == 0) pad = 8;
        size_t encLen = L + pad;

        /*----------- ③ 收满整个密文 -----------*/
        while (inBuf.size() < 4 + encLen && needMore()) {}
        if (inBuf.size() < 4 + encLen) break; // 连接断开

        /*----------- ④ 解密 -----------*/
        plainBuf.clear();
        for (size_t off = 4; off < 4 + encLen; off += 8) {
            char blk[8];
            memcpy(blk, inBuf.data() + off, 8);
            des_decrypt(blk);
            plainBuf.insert(plainBuf.end(), blk, blk + 8);
        }
        inBuf.erase(inBuf.begin(), inBuf.begin() + 4 + encLen);  // 移除已处理

        /*----------- ⑤ 去掉 PKCS#7 填充 -----------*/
        if (plainBuf.empty()) continue;
        size_t realLen = plainBuf.size() -
            static_cast<unsigned char>(plainBuf.back());
        if (realLen > plainBuf.size()) continue;  // 若填充异常，忽略此包
        std::string decrypted(plainBuf.data(), realLen);
		
        // 打印解密后的字节流
        logEvent("RECV_DECRYPTED", "[" + std::to_string(clientSock) + "] " + decrypted);

        /*----------- ⑥ 解析协议 TYPE|TARGET|BODY -----------*/
        size_t p1 = decrypted.find('|');
        size_t p2 = decrypted.find('|', p1 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        std::string type = decrypted.substr(0, p1);
        std::string target = decrypted.substr(p1 + 1, p2 - p1 - 1);
        std::string body = decrypted.substr(p2 + 1);

        // 安全日志输出，不含消息正文
        /*printf("[DEBUG] 收到协议：Type=%s | Target=%s | BodyLength=%zu 字节\n",
            type.c_str(), target.c_str(), body.size());*/
        // ====================== ↓↓↓ 原业务逻辑不变 ↓↓↓ ======================
        if (type == "LOGIN") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (user2sock.count(target)) {
                safeSend(clientSock, "SYS|-|用户名已被使用，请选择其他名称");
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
                safeSend(clientSock, "SYS|-|群组名已存在，请选择其他名称");
                continue;
            }
            groups[target].push_back(clientSock);
            groupOwners[target] = sock2user[clientSock];
            printf("[*] 用户 %s 创建了群组 %s\n",
                sock2user[clientSock].c_str(), target.c_str());
            safeSend(clientSock, "CREATE|-|" + target);

            logEvent("GROUP_CREATE", "Group:" + target + " Owner:" + sock2user[clientSock]);
        }
        // KICK 命令处理部分修复
        else if (type == "KICK") {
            std::string username;
            {
                std::lock_guard<std::mutex> lock(gMutex);
                auto it = sock2user.find(clientSock);
                if (it != sock2user.end()) {
                    username = it->second;
                }
                else {
                    safeSend(clientSock, "SYS|-|身份错误，请重新连接");
                    break;
                }
            }

            // 从 body 中获取要踢出的用户名
            std::string kickUser = body;  // body 中包含要踢出的用户名

            std::lock_guard<std::mutex> lock(gMutex);
            if (groupOwners[target] != username) {
                safeSend(clientSock, "SYS|-|您不是群主，无法执行踢人操作");
            }
            else if (user2sock.find(kickUser) == user2sock.end()) {
                safeSend(clientSock, "SYS|-|用户不存在");
            }
            else {
                SOCKET targetSock = user2sock[kickUser];
                auto& vec = groups[target];
                auto it = std::find(vec.begin(), vec.end(), targetSock);
                if (it != vec.end()) {
                    vec.erase(it);
                    // 如果该用户在禁言列表中，也一并移除
                    if (mutedUsers.count(target)) {
                        mutedUsers[target].erase(kickUser);
                    }
                    safeSend(targetSock, "SYS|-|您已被踢出群聊 " + target);
                    safeSend(clientSock, "SYS|-|已将 " + kickUser + " 踢出群聊 " + target);
                    for (SOCKET s : vec) {
                        if (s != clientSock)
                            safeSend(s, "SYS|-|用户 " + kickUser + " 已退出群聊 " + target);
                    }
                }
                else {
                    safeSend(clientSock, "SYS|-|该用户不在群聊中");
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
                    safeSend(clientSock, "SYS|-|身份错误，请重新连接");
                    break;
                }
            }

            std::lock_guard<std::mutex> lock(gMutex);
            if (groupOwners[target] != username) {
                safeSend(clientSock, "SYS|-|你不是群主，无法解散群组");
            }
            else {
                auto vec = groups[target];
                for (SOCKET s : vec) {
                    if (s != clientSock)
                        safeSend(s, "SYS|-|群组 " + target + " 已被群主解散");
                }
                groups.erase(target);
                groupOwners.erase(target);
                safeSend(clientSock, "SYS|-|你已解散群组 " + target);
            }
        }
        else if (type == "MUTE") {
            std::lock_guard<std::mutex> lock(gMutex);
            std::string operatorName = sock2user[clientSock];

            if (groupOwners[target] != operatorName) {
                safeSend(clientSock, "SYS|-|您不是群主，没有权限禁言群成员");
            }
            else {
                // 检查目标用户是否在群组内
                bool inGroup = false;
                auto& members = groups[target];
                for (SOCKET s : members) {
                    if (sock2user[s] == body) {
                        inGroup = true;
                        break;
                    }
                }
                if (!inGroup) {
                    safeSend(clientSock, "SYS|-|用户不在群内，无法禁言");
                }
                else {
                    if (user2sock.find(body) == user2sock.end() ||
                        std::find(groups[target].begin(), groups[target].end(), user2sock[body]) == groups[target].end()) {
                        safeSend(clientSock, "SYS|-|该用户不在群组中");
                    }
                    else {
                        mutedUsers[target].insert(body);
                        safeSend(clientSock, "SYS|-|已将 " + body + " 禁言");
                    }
                }

            }
            }
        else if (type == "UNMUTE") {
            std::lock_guard<std::mutex> lock(gMutex);
            std::string operatorName = sock2user[clientSock];

            if (groupOwners[target] != operatorName) {
                safeSend(clientSock, "SYS|-|你不是群主，无法解除禁言");
            }
            else if (user2sock.find(body) == user2sock.end() ||
                std::find(groups[target].begin(), groups[target].end(), user2sock[body]) == groups[target].end()) {
                safeSend(clientSock, "SYS|-|该用户不在群组中");
            }
            else if (!mutedUsers.count(target) || mutedUsers[target].count(body) == 0) {
                safeSend(clientSock, "SYS|-|该用户未被禁言，无法解除");
            }
            else {
                mutedUsers[target].erase(body);
                safeSend(clientSock, "SYS|-|已将 " + body + " 解除禁言");
            }
        }
        else if (type == "PRIVATE") {
            SOCKET dst;
            {
                std::lock_guard<std::mutex> lock(gMutex);
                if (!user2sock.count(target)) {
                    safeSend(clientSock, "SYS|-|用户不存在或已离线");
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
                safeSend(clientSock, "SYS|-|群组不存在，请先创建或检查名称");
                continue;
            }
            auto& members = groups[target];
            if (std::find(members.begin(), members.end(), clientSock) != members.end()) {
                safeSend(clientSock, "SYS|-|您已经在该群组中");
                continue;
            }
            members.push_back(clientSock);
            std::string username = sock2user[clientSock];
            printf("[*] 用户 %s 加入了群组 %s\n", username.c_str(), target.c_str());
            safeSend(clientSock, "JOIN|-|" + target);
            for (SOCKET s : members)
                if (s != clientSock)
                    safeSend(s, "SYS|-|用户 " + username + " 加入了群组 " + target);
			logEvent("GROUP_JOIN", "Group:" + target + " User:" + username);
        }
        else if (type == "LEAVE") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (!groups.count(target)) {
                safeSend(clientSock, "SYS|-|群组不存在");
                continue;
            }
            auto& vec = groups[target];
            auto  itMember = std::find(vec.begin(), vec.end(), clientSock);
            if (itMember == vec.end()) {
                safeSend(clientSock, "SYS|-|您不在该群组中");
                continue;
            }

            std::string username = sock2user[clientSock];
            vec.erase(itMember);

            // 群主转移
            if (groupOwners[target] == username && !vec.empty()) {
                SOCKET newSock = vec.front();
                std::string newBoss = sock2user[newSock];
                groupOwners[target] = newBoss;
                safeSend(newSock, "SYS|-|您已成为群组 " + target + " 的新管理员");
                for (SOCKET s : vec)
                    if (s != newSock)
                        safeSend(s, "SYS|-|用户 " + newBoss + " 已成为群组 "
                            + target + " 的新管理员");
            }

            if (vec.empty()) {
                groups.erase(target);
                groupOwners.erase(target);
                printf("[*] 群组 %s 已被删除\n", target.c_str());
            }

            safeSend(clientSock, "LEAVE|-|" + target);
            // 向群内其他成员广播用户退出
            for (SOCKET s : vec) {
                if (s != clientSock) {
                    safeSend(s, "SYS|-|用户 " + username + " 已退出群组 " + target);
                }
            }

			logEvent("GROUP_LEAVE", "Group:" + target + " User:" + username);
        }
        else if (type == "MEMBERS") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (groups.find(target) == groups.end()) {
                safeSend(clientSock, "SYS|-|群组不存在");
            }
            else {
                std::string list = "SYS|-|群组成员：";
                for (SOCKET s : groups[target]) {
                    list += sock2user[s] + " ";
                }
                safeSend(clientSock, list);
            }
        }
        else if (type == "GROUP") {
            std::string sender = sock2user[clientSock];
            std::lock_guard<std::mutex> lock(gMutex);

            // 检查群是否存在
            if (!groups.count(target)) {
                safeSend(clientSock, "SYS|-|群组不存在");
                continue;
            }

            // 检查是否仍在群中
            auto& members = groups[target];
            if (std::find(members.begin(), members.end(), clientSock) == members.end()) {
                safeSend(clientSock, "SYS|-|您已不在该群组中，无法发言");
                continue;
            }


            // 检查是否被禁言
            if (mutedUsers[target].count(sender)) {
                safeSend(clientSock, "SYS|-|你已被群主禁言，无法发言");
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
                safeSend(clientSock, "SYS|-|群组不存在");
                continue;
            }

            const auto& groupMembers = groups[target];
            if (std::find(groupMembers.begin(), groupMembers.end(), clientSock) == groupMembers.end()) {
                safeSend(clientSock, "SYS|-|您不在该群组中，无法查看禁言列表");
                continue;
            }

            std::string list;
            for (const auto& name : mutedUsers[target]) {
                list += name + "\n";
            }
            if (list.empty()) list = "(无禁言成员)";

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
                        list += " (群主: " + groupOwners[kv.first] + ")";
                    list += ",";
                }
                if (!list.empty()) list.pop_back();
                safeSend(clientSock, "GROUPS|-|" + list);
            }
        }
        // ====================== ↑↑↑ 业务逻辑结束 ↑↑↑ ======================
    }


    std::string username = sock2user[clientSock];
    logEvent("DISCONNECT", "User:" + username + " IP:" + clientIP + " Socket:" + std::to_string(clientSock));
    /*------------- 清理离线用户信息 -------------*/
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
        // 初始化DES加密
        if (des_init(0) == 0) {
            fprintf(stderr, "DES初始化失败\n");
            return 1;
        }
        des_set_key((char*)"mykey12"); // 必须与客户端密钥一致

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

        printf("[*] 安全聊天服务器已启动 (DES加密已启用) 端口: %d...\n", DEFAULT_PORT);

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

        // 清理资源（理论上不会执行到这里）
        des_done();
        closesocket(srv);
        WSACleanup();
    }
    catch (const std::exception& e) {
        des_done();
        WSACleanup();

        logEvent("SERVER", "!!! Server Crashed !!!");
        fprintf(stderr, "服务器异常终止: %s\n", e.what());
    }
    logEvent("SERVER", "=== Server Stopped ===");
    return 0;
}
