// Server.cpp
#include "Server.h"
#pragma comment(lib, "ws2_32.lib")

std::mutex gMutex;
std::unordered_map<SOCKET, string> sock2user;
std::unordered_map<string, SOCKET> user2sock;
std::unordered_map<string, vector<SOCKET>> groups;
std::unordered_map<string, string> groupOwners; // Mapping of group and group creator
std::unordered_map<std::string, std::unordered_set<std::string>> mutedUsers;
std::mutex logMutex;  // Mutex for the log file
std::string adminUser = ""; // 当前管理员用户名


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
    if (!hex.empty()) hex.pop_back(); // Remove the last space
    return hex;
}

static void logEvent(const std::string& type, const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    FILE* logFile = nullptr;
    fopen_s(&logFile, "server.log", "a");
    if (logFile) {
        // Get the current time
        time_t now = time(nullptr);
        struct tm tmBuf;
        localtime_s(&tmBuf, &now);
        char timeStr[64];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &tmBuf);

        // Write to the log file
        fprintf(logFile, "[%s][%s] %s\n", timeStr, type.c_str(), message.c_str());
        fclose(logFile);
    }
}

void safeSend(SOCKET s, const std::string& msg) {
    //// PKCS#7 padding
    //size_t pad = 8 - (msg.size() % 8);
    //std::string padded = msg + std::string(pad, static_cast<char>(pad));

    //// DES encryption
    //std::vector<char> encrypted;
    //for (size_t i = 0; i < padded.size(); i += 8) {
    //    char block[8];
    //    memcpy(block, padded.c_str() + i, 8);
    //    des_encrypt(block);
    //    encrypted.insert(encrypted.end(), block, block + 8);
    //}

    //// Send the encrypted data
    //int ret = send(s, encrypted.data(), encrypted.size(), 0);
    //if (ret == SOCKET_ERROR) {
    //    fprintf(stderr, "[!] send() error %d on socket %llu\n",
    //        WSAGetLastError(), static_cast<unsigned long long>(s));
    //}

    // --- 1. PKCS#7 padding ---
    logEvent("SEND_PLAIN", "[" + std::to_string(s) + "] " + msg);
    size_t pad = 8 - (msg.size() % 8);
    if (pad == 0) pad = 8;
    std::string padded = msg + std::string(pad, static_cast<char>(pad));

    // --- 2. Encryption ---
    std::vector<char> enc;
    enc.reserve(padded.size());
    for (size_t i = 0; i < padded.size(); i += 8) {
        char blk[8]; memcpy(blk, padded.data() + i, 8);
        des_encrypt(blk);
        enc.insert(enc.end(), blk, blk + 8);
    }
    // Print the encrypted byte stream
    /*std::cout << "[Encrypted message]: ";
    for (char c : enc) {
        std::cout << std::hex << (0xFF & c) << " ";
    }
    std::cout << std::endl;*/

    logEvent("SEND_ENCRYPTED", "[" + std::to_string(s) + "] " + bytesToHex(enc.data(), enc.size()));

    // --- 3. Send with a 4-byte length header ---
    uint32_t L = htonl(static_cast<uint32_t>(msg.size()));  // Cleartext length
    if (send(s, reinterpret_cast<char*>(&L), 4, 0) == SOCKET_ERROR ||
        send(s, enc.data(), static_cast<int>(enc.size()), 0) == SOCKET_ERROR) {
        logEvent("SEND_ERROR", "[" + std::to_string(s) + "] send failed, code: " + std::to_string(WSAGetLastError()));
    }
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
            return; // If not found, jump out directly
        }
    }

    // Clean up group members
    for (auto it = groups.begin(); it != groups.end();) {
        auto& vec = it->second;
        vec.erase(std::remove(vec.begin(), vec.end(), deadSock), vec.end());

        // If the group is empty, remove the group
        if (vec.empty()) {
            groupOwners.erase(it->first); // Remove group owner information
            it = groups.erase(it);
        }
        else {
            ++it;
        }
    }
}

// Server side: Handle a single client connection (supports explicit length header + DES decryption, no more misjudgment due to padding)
void handleClient(SOCKET clientSock, sockaddr_in addr)
{
    std::vector<char> inBuf;                  // Original receive buffer
    std::vector<char> plainBuf;               // Decrypted cleartext
    char ipStr[INET_ADDRSTRLEN]{};
    char tmp[BUFFER_SIZE];

    // Get the client IP string
    if (inet_ntop(AF_INET, &addr.sin_addr, ipStr, INET_ADDRSTRLEN) == nullptr) {
        perror("inet_ntop error");
        return;
    }
    std::string clientIP(ipStr);

    logEvent("CONNECT", "Socket:" + std::to_string(clientSock) + " IP:" + clientIP);

    // ----------------------- Initialize the default username -----------------------
    {
        std::lock_guard<std::mutex> lock(gMutex);
        std::string defName = "Guest_" + clientIP + "_" + std::to_string(clientSock);
        sock2user[clientSock] = defName;
        user2sock[defName] = clientSock;
    }
    printf("[+] %s connected (%llu)\n", clientIP.c_str(),
        static_cast<unsigned long long>(clientSock));

    // ----------------------- Receive packet helper lambda -----------------------
    auto needMore = [&](void) -> bool {
        int n = recv(clientSock, tmp, BUFFER_SIZE, 0);
        if (n <= 0) {
            return false;                     // Peer closed or error
        }
        inBuf.insert(inBuf.end(), tmp, tmp + n);
        return true;
        };

    // ======================= Main loop: Read by packet =======================
    std::string type, target, extra;
    while (true)
    {
        /*----------- ① First, ensure there is a 4-byte length header -----------*/
        while (inBuf.size() < 4 && needMore()) {}
        if (inBuf.size() < 4) break;          // Connection closed

        uint32_t L;
        memcpy(&L, inBuf.data(), 4);
        L = ntohl(L);                         // Cleartext length

        /*----------- ② Calculate the ciphertext length (including padding) -----------*/
        size_t pad = 8 - (L % 8);
        if (pad == 0) pad = 8;
        size_t encLen = L + pad;

        /*----------- ③ Receive the entire ciphertext -----------*/
        while (inBuf.size() < 4 + encLen && needMore()) {}
        if (inBuf.size() < 4 + encLen) break; // Connection closed

        /*----------- ④ Decryption -----------*/
        plainBuf.clear();
        for (size_t off = 4; off < 4 + encLen; off += 8) {
            char blk[8];
            memcpy(blk, inBuf.data() + off, 8);
            des_decrypt(blk);
            plainBuf.insert(plainBuf.end(), blk, blk + 8);
        }
        inBuf.erase(inBuf.begin(), inBuf.begin() + 4 + encLen);  // Remove the processed data

        /*----------- ⑤ Remove PKCS#7 padding -----------*/
        if (plainBuf.empty()) continue;
        size_t realLen = plainBuf.size() -
            static_cast<unsigned char>(plainBuf.back());
        if (realLen > plainBuf.size()) continue;  // If the padding is abnormal, ignore this packet
        std::string decrypted(plainBuf.data(), realLen);

        // Print the decrypted byte stream
        logEvent("RECV_DECRYPTED", "[" + std::to_string(clientSock) + "] " + decrypted);

        /*----------- ⑥ Parse the protocol TYPE|TARGET|BODY -----------*/
        size_t p1 = decrypted.find('|');
        size_t p2 = decrypted.find('|', p1 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        std::string type = decrypted.substr(0, p1);
        std::string target = decrypted.substr(p1 + 1, p2 - p1 - 1);
        std::string body = decrypted.substr(p2 + 1);

        // Safe log output, without the message body
        /*printf("[DEBUG] Received protocol: Type=%s | Target=%s | BodyLength=%zu bytes\n",
            type.c_str(), target.c_str(), body.size());*/
            // ====================== ↓↓↓ Original business logic remains unchanged ↓↓↓ ======================
        if (type == "LOGIN") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (user2sock.count(target)) {
                safeSend(clientSock, "SYS|-|Username already in use, please choose another name");
                continue;
            }
            std::string old = sock2user[clientSock];
            user2sock.erase(old);
            sock2user[clientSock] = target;
            user2sock[target] = clientSock;

            // 设置管理员
            if (target == "admin") {
                adminUser = target;
                safeSend(clientSock, "LOGIN|-|" + target + " (You are now the admin)");
            }
            else {
                safeSend(clientSock, "LOGIN|-|" + target);
            }

            logEvent("USER_LOGIN", "[" + std::to_string(clientSock) + "] " + target);
        }

        else if (type == "CREATE") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (groups.count(target)) {
                std::string currentOwner = groupOwners.count(target) ? groupOwners[target] : "(unknown)";
                safeSend(clientSock, "SYS|-|group [" + target + "] alreayd exist，creater is " + currentOwner);
                continue;
            }
            groups[target].push_back(clientSock);
            groupOwners[target] = sock2user[clientSock];
            printf("[*] User %s created group %s\n",
                sock2user[clientSock].c_str(), target.c_str());
            safeSend(clientSock, "CREATE|-|" + target);

            logEvent("GROUP_CREATE", "Group:" + target + " Owner:" + sock2user[clientSock]);
        }
        // KICK command processing part fixed
        else if (type == "KICK") {
            std::string username;
            {
                std::lock_guard<std::mutex> lock(gMutex);
                auto it = sock2user.find(clientSock);
                if (it != sock2user.end()) {
                    username = it->second;
                }
                else {
                    safeSend(clientSock, "SYS|-|Identity error, please reconnect");
                    break;
                }
            }

            // Get the username to be kicked from the body
            std::string kickUser = body;  // The body contains the username to be kicked

            std::lock_guard<std::mutex> lock(gMutex);
            if (groupOwners[target] != username) {
                safeSend(clientSock, "SYS|-|You are not the group owner and cannot perform the kick operation");
            }
            else if (user2sock.find(kickUser) == user2sock.end()) {
                safeSend(clientSock, "SYS|-|User does not exist");
            }
            else {
                SOCKET targetSock = user2sock[kickUser];
                auto& vec = groups[target];
                auto it = std::find(vec.begin(), vec.end(), targetSock);
                if (it != vec.end()) {
                    vec.erase(it);
                    // If the user is in the muted list, remove it as well
                    if (mutedUsers.count(target)) {
                        mutedUsers[target].erase(kickUser);
                    }
                    safeSend(targetSock, "SYS|-|You have been kicked out of the group " + target);
                    safeSend(clientSock, "SYS|-|User " + kickUser + " has been kicked out of the group " + target);
                    for (SOCKET s : vec) {
                        if (s != clientSock)
                            safeSend(s, "SYS|-|User " + kickUser + " has left the group " + target);
                    }
                }
                else {
                    safeSend(clientSock, "SYS|-|The user is not in the group");
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
                    safeSend(clientSock, "SYS|-|Identity error, please reconnect");
                    break;
                }
            }

            std::lock_guard<std::mutex> lock(gMutex);
            if (groupOwners[target] != username) {
                safeSend(clientSock, "SYS|-|You are not the group owner and cannot disband the group");
            }
            else {
                auto vec = groups[target];
                for (SOCKET s : vec) {
                    if (s != clientSock)
                        safeSend(s, "SYS|-|Group " + target + " has been disbanded by the group owner");
                }
                groups.erase(target);
                groupOwners.erase(target);
                safeSend(clientSock, "SYS|-|You have disbanded the group " + target);
            }
        }
        else if (type == "MUTE") {
            std::lock_guard<std::mutex> lock(gMutex);
            std::string operatorName = sock2user[clientSock];

            if (groupOwners[target] != operatorName) {
                safeSend(clientSock, "SYS|-|You are not the group owner and have no permission to mute group members");
            }
            else {
                // Check if the target user is in the group
                bool inGroup = false;
                auto& members = groups[target];
                for (SOCKET s : members) {
                    if (sock2user[s] == body) {
                        inGroup = true;
                        break;
                    }
                }
                if (!inGroup) {
                    safeSend(clientSock, "SYS|-|The user is not in the group and cannot be muted");
                }
                else {
                    if (user2sock.find(body) == user2sock.end() ||
                        std::find(groups[target].begin(), groups[target].end(), user2sock[body]) == groups[target].end()) {
                        safeSend(clientSock, "SYS|-|The user is not in the group");
                    }
                    else {
                        mutedUsers[target].insert(body);
                        safeSend(clientSock, "SYS|-|User " + body + " has been muted");
                    }
                }
            }
        }
        else if (type == "UNMUTE") {
            std::lock_guard<std::mutex> lock(gMutex);
            std::string operatorName = sock2user[clientSock];

            if (groupOwners[target] != operatorName) {
                safeSend(clientSock, "SYS|-|You are not the group owner and cannot unmute");
            }
            else if (user2sock.find(body) == user2sock.end() ||
                std::find(groups[target].begin(), groups[target].end(), user2sock[body]) == groups[target].end()) {
                safeSend(clientSock, "SYS|-|The user is not in the group");
            }
            else if (!mutedUsers.count(target) || mutedUsers[target].count(body) == 0) {
                safeSend(clientSock, "SYS|-|The user is not muted and cannot be unmuted");
            }
            else {
                mutedUsers[target].erase(body);
                safeSend(clientSock, "SYS|-|User " + body + " has been unmuted");
            }
        }
        else if (type == "ASSIGN") {
            std::lock_guard<std::mutex> lock(gMutex);
            std::string sender = sock2user[clientSock];

            // 权限校验
            if (sender != "admin") {
                safeSend(clientSock, "SYS|-|only admin can add user to the group");
            }
            else if (user2sock.find(body) == user2sock.end()) {
                safeSend(clientSock, "SYS|-|user does not exist");
            }
            else {
                SOCKET userSock = user2sock[body];

                // 如果群组不存在，自动创建，并将群主设置为 admin
                if (!groups.count(target)) {
                    groups[target] = {};
                    groupOwners[target] = "admin";
                }

                auto& members = groups[target];
                if (std::find(members.begin(), members.end(), userSock) != members.end()) {
                    safeSend(clientSock, "SYS|-|User already in the group");
                }
                else {
                    members.push_back(userSock);
                    safeSend(userSock, "JOIN|-|" + target);
                    safeSend(userSock, "SYS|-|You are added to the group by admin " + target);
                    safeSend(clientSock, "SYS|-|User " + body + " have been added to the group " + target);

                    for (SOCKET s : members) {
                        if (s != clientSock && s != userSock)
                            safeSend(s, "SYS|-|User " + body + " have been added to the group by admin " + target);
                    }

                    logEvent("ADMIN_ASSIGN", "Admin assigned user " + body + " to group " + target);
                }
            }
        }

        else if (type == "PRIVATE") {
            SOCKET dst;
            {
                std::lock_guard<std::mutex> lock(gMutex);
                if (!user2sock.count(target)) {
                    safeSend(clientSock, "SYS|-|The user does not exist or is offline");
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
                safeSend(clientSock, "SYS|-|The group does not exist, please create it or check the name");
                continue;
            }
            auto& members = groups[target];
            if (std::find(members.begin(), members.end(), clientSock) != members.end()) {
                safeSend(clientSock, "SYS|-|You are already in this group");
                continue;
            }
            members.push_back(clientSock);
            std::string username = sock2user[clientSock];
            printf("[*] User %s joined group %s\n", username.c_str(), target.c_str());
            safeSend(clientSock, "JOIN|-|" + target);
            for (SOCKET s : members)
                if (s != clientSock)
                    safeSend(s, "SYS|-|User " + username + " joined group " + target);
            logEvent("GROUP_JOIN", "Group:" + target + " User:" + username);
        }
        else if (type == "LEAVE") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (!groups.count(target)) {
                safeSend(clientSock, "SYS|-|The group does not exist");
                continue;
            }
            auto& vec = groups[target];
            auto  itMember = std::find(vec.begin(), vec.end(), clientSock);
            if (itMember == vec.end()) {
                safeSend(clientSock, "SYS|-|You are not in this group");
                continue;
            }

            std::string username = sock2user[clientSock];
            vec.erase(itMember);

            // Transfer group ownership
            if (groupOwners[target] == username && !vec.empty()) {
                SOCKET newSock = vec.front();
                std::string newBoss = sock2user[newSock];
                groupOwners[target] = newBoss;
                safeSend(newSock, "SYS|-|You have become the new administrator of group " + target);
                for (SOCKET s : vec)
                    if (s != newSock)
                        safeSend(s, "SYS|-|User " + newBoss + " has become the new administrator of group " + target);
            }

            if (vec.empty()) {
                groups.erase(target);
                groupOwners.erase(target);
                printf("[*] Group %s has been deleted\n", target.c_str());
            }

            safeSend(clientSock, "LEAVE|-|" + target);
            // Broadcast the user's exit to other group members
            for (SOCKET s : vec) {
                if (s != clientSock) {
                    safeSend(s, "SYS|-|User " + username + " has left group " + target);
                }
            }

            logEvent("GROUP_LEAVE", "Group:" + target + " User:" + username);
        }
        else if (type == "MEMBERS") {
            std::lock_guard<std::mutex> lock(gMutex);
            if (groups.find(target) == groups.end()) {
                safeSend(clientSock, "SYS|-|The group does not exist");
            }
            else {
                std::string list = "SYS|-|Group members: ";
                for (SOCKET s : groups[target]) {
                    list += sock2user[s] + " ";
                }
                safeSend(clientSock, list);
            }
        }
        else if (type == "GROUP") {
            std::string sender = sock2user[clientSock];
            std::lock_guard<std::mutex> lock(gMutex);

            // Check if the group exists
            if (!groups.count(target)) {
                safeSend(clientSock, "SYS|-|The group does not exist");
                continue;
            }

            // Check if still in the group
            auto& members = groups[target];
            if (std::find(members.begin(), members.end(), clientSock) == members.end()) {
                safeSend(clientSock, "SYS|-|You are not in this group and cannot speak");
                continue;
            }

            // Check if muted
            if (mutedUsers[target].count(sender)) {
                safeSend(clientSock, "SYS|-|You have been muted by the group owner and cannot speak");
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
                safeSend(clientSock, "SYS|-|The group does not exist");
                continue;
            }

            const auto& groupMembers = groups[target];
            if (std::find(groupMembers.begin(), groupMembers.end(), clientSock) == groupMembers.end()) {
                safeSend(clientSock, "SYS|-|You are not in this group and cannot view the muted list");
                continue;
            }

            std::string list;
            for (const auto& name : mutedUsers[target]) {
                list += name + "\n";
            }
            if (list.empty()) list = "(No muted members)";

            safeSend(clientSock, "MUTED|" + target + "|" + list);
            logEvent("GROUP_MUTED_LIST", "Group:" + target + " User:" + sock2user[clientSock]);
        }
        else if (type == "DELETEUSER") {
            std::lock_guard<std::mutex> lock(gMutex);
            std::string admin = sock2user[clientSock];

            // 限定管理员才能删除用户
            if (admin != "admin") {
                safeSend(clientSock, "SYS|-|Only the administrator can perform this operation.");
            }
            else if (user2sock.find(target) == user2sock.end()) {
                safeSend(clientSock, "SYS|-|User does not exist");
            }
            else {
                SOCKET targetSock = user2sock[target];

                // 从所有群组中移除该用户
                std::vector<std::string> groupsToRemove;

                for (auto it = groups.begin(); it != groups.end(); ++it) {
                    const std::string& group = it->first;
                    auto& members = it->second;

                    members.erase(std::remove(members.begin(), members.end(), targetSock), members.end());
                    mutedUsers[group].erase(target);

                    if (groupOwners[group] == target) {
                        if (!members.empty()) {
                            std::string newOwner = sock2user[members[0]];
                            groupOwners[group] = newOwner;
                            safeSend(members[0], "SYS|-|You have been the new group administrator of group" + group);
                        }
                        else {
                            groupsToRemove.push_back(group);  // 延迟删除
                        }
                    }
                }

                sock2user.erase(targetSock);
                user2sock.erase(target);

                safeSend(targetSock, "SYS|-|Your account has been deleted by admin.");
                safeSend(clientSock, "SYS|-|User " + target + " has been deleted successfully.");
                shutdown(targetSock, SD_BOTH);
                closesocket(targetSock);

                logEvent("ADMIN_DELETE", "admin delete user " + target);
            }
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
                        list += " (Group owner: " + groupOwners[kv.first] + ")";
                    list += ",";
                }
                if (!list.empty()) list.pop_back();
                safeSend(clientSock, "GROUPS|-|" + list);
            }
        }
        // ====================== ↑↑↑ Business logic ends ↑↑↑ ======================
    }

    std::string username = sock2user[clientSock];
    logEvent("DISCONNECT", "User:" + username + " IP:" + clientIP + " Socket:" + std::to_string(clientSock));
    /*------------- Clean up offline user information -------------*/
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
        // Initialize DES encryption
        if (des_init(0) == 0) {
            fprintf(stderr, "DES initialization failed\n");
            return 1;
        }
        des_set_key((char*)"mykey12"); // Must be the same as the client key

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

        printf("[*] Secure chat server started (DES encryption enabled) on port: %d...\n", DEFAULT_PORT);

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

        // Clean up resources (theoretically will not reach here)
        des_done();
        closesocket(srv);
        WSACleanup();
    }
    catch (const std::exception& e) {
        des_done();
        WSACleanup();

        logEvent("SERVER", "!!! Server Crashed !!!");
        fprintf(stderr, "Server terminated abnormally: %s\n", e.what());
    }
    logEvent("SERVER", "=== Server Stopped ===");
    return 0;
}