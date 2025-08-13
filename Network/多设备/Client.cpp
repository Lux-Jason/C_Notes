//Client.cpp
#define _WIN32_WINNT 0x0600  // Minimum Windows Vista version for inet_pton
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <thread>  // Requires C++11 or later
#include <ws2tcpip.h>
#include "DES_c.h" 
#pragma comment(lib, "ws2_32.lib")

constexpr int DEFAULT_PORT = 5000;
constexpr int BUFFER_SIZE = 1024;
std::atomic<bool> isRunning(true);

// Client state information
struct ClientState {
    std::string username;
    std::vector<std::string> joinedGroups;
    std::vector<std::string> ownedGroups; // List of groups created by the user
} clientState;

void PrintHelp() {
    std::cout << "\nAvailable commands:\n"
        << "/login <username>       - Login/change nickname\n"
        << "/create <groupname>     - Create new group\n"
        << "/kick <group> <user>    - Group owner kick member\n"
        << "/disband <group>        - Group owner disband group\n"
        << "/mute <group> <user>    - Group owner mute member\n"
        << "/unmute <group> <user>  - Group owner unmute member\n"
        << "/join <group>           - Join group\n"
        << "/leave <group>          - Leave group\n"
        << "/members <group>        - List group members\n"
        << "/muted <group>          - List muted users\n"
        << "/list                 - List online users\n"
        << "/listgroups           - List all available groups\n"
        << "/private <user> <msg> - Private message\n"
        << "/group <group> <msg>  - Group message\n"
        << "/public <message>     - Broadcast message\n"
        << "/exit                 - Exit program\n"
        << "/help                 - Show help\n";
}

// -------- Client receive thread: Handles length header + DES decryption --------
void MessageReceiver(SOCKET sock)
{
    std::vector<char> inBuf;               // Raw packet buffer
    std::vector<char> plainBuf;            // Decrypted plaintext
    char tmp[BUFFER_SIZE];

    auto needMore = [&](void) -> bool {
        int n = recv(sock, tmp, BUFFER_SIZE, 0);
        if (n <= 0) {
            if (n == 0) {
                std::cerr << "\n[System]: Server closed, connection lost.\n";
            }
            else {
                std::cerr << "\n[System]: Data receive failed, error code: " << WSAGetLastError() << std::endl;
            }
            isRunning = false;
            return false;
        }

        inBuf.insert(inBuf.end(), tmp, tmp + n);
        return true;
        };

    while (isRunning)
    {
        /*------------------- ① Parse 4-byte plaintext length header -------------------*/
        while (inBuf.size() < 4 && needMore()) {}
        if (inBuf.size() < 4) break;       // 断线

        uint32_t L;
        memcpy(&L, inBuf.data(), 4);
        L = ntohl(L);                      // 明文长度

        /*------------------- ② Calculate required encryption bytes -------------------*/
        size_t pad = 8 - (L % 8);
        if (pad == 0) pad = 8;
        size_t encLen = L + pad;           // 密文总长度

        /*------------------- ③ Receive complete ciphertext -------------------*/
        while (inBuf.size() < 4 + encLen && needMore()) {}
        if (inBuf.size() < 4 + encLen) break;   // 断线

        /*------------------- ④ Decrypt entire message -------------------*/
        plainBuf.clear();
        for (size_t off = 4; off < 4 + encLen; off += 8) {
            char blk[8];
            memcpy(blk, inBuf.data() + off, 8);
            des_decrypt(blk);
            plainBuf.insert(plainBuf.end(), blk, blk + 8);
        }
        inBuf.erase(inBuf.begin(), inBuf.begin() + 4 + encLen); // 移除已处理字节

        /*------------------- ⑤ Remove PKCS#7 padding -------------------*/
        if (plainBuf.empty()) continue;    // 防御性检查
        size_t realLen = plainBuf.size() - static_cast<unsigned char>(plainBuf.back());
        if (realLen > plainBuf.size()) continue; // 填充异常，忽略
        std::string msg(plainBuf.data(), realLen);

        /*------------------- ⑥ Parse "TYPE|FROM|CONTENT" protocol -------------------*/
        size_t p1 = msg.find('|');
        size_t p2 = msg.find('|', p1 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        std::string type = msg.substr(0, p1);
        std::string from = msg.substr(p1 + 1, p2 - p1 - 1);
        std::string content = msg.substr(p2 + 1);

        if (type == "PRIVATE") {
            std::cout << "\n[Private from " << from << "]: " << content << std::endl;
        }
        else if (type == "GROUP") {
            size_t separator = content.find('|');
            if (separator != std::string::npos) {
                std::string sender = content.substr(0, separator);
                std::string message = content.substr(separator + 1);
                std::cout << "\n[Group " << from << " from " << sender << "]: " << message << std::endl;
            }
        }
        else if (type == "PUBLIC") {
            std::cout << "\n[Broadcast from " << from << "]: " << content << std::endl;
        }
        else if (type == "USERS") {
            std::replace(content.begin(), content.end(), ',', '\n');
            std::cout << "\nOnline Users List:\n" << content << std::endl;
        }
        else if (type == "GROUPS") {
            std::replace(content.begin(), content.end(), ',', '\n');
            std::cout << "\nAvailable Groups List:\n" << content << std::endl;
        }
        else if (type == "LOGIN") {
            std::cout << "\n[Login success]: " << content << std::endl;
            clientState.username = content;
        }
        else if (type == "CREATE") {
            std::cout << "\n[Group created]: " << content << std::endl;
            clientState.ownedGroups.push_back(content);
            clientState.joinedGroups.push_back(content);
        }
        else if (type == "JOIN") {
            std::cout << "\n[Joined group]: " << content << std::endl;
            if (std::find(clientState.joinedGroups.begin(),
                clientState.joinedGroups.end(), content) == clientState.joinedGroups.end()) {
                clientState.joinedGroups.push_back(content);
            }
        }
        else if (type == "LEAVE") {
            std::cout << "\n[Left group]: " << content << std::endl;
            auto it = std::find(clientState.joinedGroups.begin(),
                clientState.joinedGroups.end(), content);
            if (it != clientState.joinedGroups.end()) {
                clientState.joinedGroups.erase(it);
            }
            auto it2 = std::find(clientState.ownedGroups.begin(),
                clientState.ownedGroups.end(), content);
            if (it2 != clientState.ownedGroups.end()) {
                clientState.ownedGroups.erase(it2);
            }
        }
        else if (type == "SYS") {
            std::cout << "\n[System message]: " << content << std::endl;
        }
        else if (type == "MUTED") {
            std::cout << "\n[Muted members in group " << from << "]:\n" << content << std::endl;
        }

        std::cout << "Enter command (? for help): ";
        std::cout.flush();
    }
}

void SendMessage(SOCKET sock, const std::string& msg) {
    // --- 1. PKCS#7 填充 ---
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

    // --- 3. 带 4 字节长度头发送 ---
    uint32_t L = htonl(static_cast<uint32_t>(msg.size()));  // 明文长度
    send(sock, reinterpret_cast<char*>(&L), 4, 0);
    send(sock, enc.data(), static_cast<int>(enc.size()), 0);
}

void HandleInput(SOCKET sock) {
    std::string input;
    PrintHelp();

    while (isRunning) {
        std::cout << "Enter command (? for help): ";
        std::getline(std::cin, input);

        if (input.empty()) continue;

        if (input[0] == '/') {
            size_t space = input.find(' ');
            std::string cmd = input.substr(1, space - 1);
            std::string args = (space != std::string::npos) ? input.substr(space + 1) : "";

            if (cmd == "login") {
                if (!args.empty()) {
                    SendMessage(sock, "LOGIN|" + args + "|-");
                }
                else {
                    std::cout << "[Error]: Please provide username, e.g.: /login username" << std::endl;
                }
            }
            else if (cmd == "create") {
                if (!args.empty()) {
                    SendMessage(sock, "CREATE|" + args + "|-");
                }
                else {
                    std::cout << "[Error]: Please provide group name, e.g.: /create groupname" << std::endl;
                }
            }
            else if (cmd == "kick") {
                // 解析群组名和用户名
                size_t split = args.find(' ');
                if (split != std::string::npos) {
                    std::string group = args.substr(0, split);
                    std::string user = args.substr(split + 1);

                    // 检查当前用户是否为群主
                    if (std::find(clientState.ownedGroups.begin(),
                        clientState.ownedGroups.end(), group) != clientState.ownedGroups.end()) {
                        SendMessage(sock, "KICK|" + group + "|" + user);
                    }
                    else {
                        std::cout << "[Error]: You're not group owner, cannot kick members" << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: Please provide group and user, e.g.: /kick groupname username" << std::endl;
                }
            }
            else if (cmd == "disband") {
                if (!args.empty()) {
                    // 检查当前用户是否为群主
                    if (std::find(clientState.ownedGroups.begin(),
                        clientState.ownedGroups.end(), args) != clientState.ownedGroups.end()) {
                        SendMessage(sock, "DISBAND|" + args + "|-");

                        // 本地清除群组信息
                        auto it1 = std::find(clientState.ownedGroups.begin(),
                            clientState.ownedGroups.end(), args);
                        if (it1 != clientState.ownedGroups.end())
                            clientState.ownedGroups.erase(it1);

                        auto it2 = std::find(clientState.joinedGroups.begin(),
                            clientState.joinedGroups.end(), args);
                        if (it2 != clientState.joinedGroups.end())
                            clientState.joinedGroups.erase(it2);
                    }
                    else {
                        std::cout << "[Error]: You're not group owner, cannot disband group" << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: Please provide group name, e.g.: /disband groupname" << std::endl;
                }
            }
            else if (cmd == "mute") {
                size_t split = args.find(' ');
                if (split != std::string::npos) {
                    std::string group = args.substr(0, split);
                    std::string user = args.substr(split + 1);
                    SendMessage(sock, "MUTE|" + group + "|" + user);
                }
                else {
                    std::cout << "[Error]: /mute group username\n";
                }
            }
            else if (cmd == "unmute") {
                size_t split = args.find(' ');
                if (split != std::string::npos) {
                    std::string group = args.substr(0, split);
                    std::string user = args.substr(split + 1);
                    SendMessage(sock, "UNMUTE|" + group + "|" + user);
                }
                else {
                    std::cout << "[Error]: /unmute group username\n";
                }
            }
            else if (cmd == "muted") {
                if (!args.empty()) {
                    // 检查是否在该群中
                    if (std::find(clientState.joinedGroups.begin(),
                        clientState.joinedGroups.end(), args) != clientState.joinedGroups.end()) {
                        SendMessage(sock, "MUTED|" + args + "|-");
                    }
                    else {
                        std::cout << "[Error]: You're not in this group, cannot view muted members" << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: Format: /muted groupname" << std::endl;
                }
            }
            else if (cmd == "members") {
                if (!args.empty()) {
                    // 检查用户是否在群组中
                    if (std::find(clientState.joinedGroups.begin(),
                        clientState.joinedGroups.end(), args) != clientState.joinedGroups.end()) {
                        SendMessage(sock, "MEMBERS|" + args + "|-");
                    }
                    else {
                        std::cout << "[Error]: You're not in this group, cannot view members" << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: Please provide group name, e.g.: /members groupname" << std::endl;
                }
            }
            else if (cmd == "join") {
                if (!args.empty()) {
                    SendMessage(sock, "JOIN|" + args + "|-");
                }
                else {
                    std::cout << "[Error]: Please provide group name, e.g.: /join groupname" << std::endl;
                }
            }
            else if (cmd == "leave") {
                if (!args.empty()) {
                    SendMessage(sock, "LEAVE|" + args + "|-");
                }
                else {
                    std::cout << "[Error]: Please provide group name, e.g.: /leave groupname" << std::endl;
                }
            }
            else if (cmd == "list") {
                SendMessage(sock, "LIST|USERS|-");
            }
            else if (cmd == "listgroups") {
                SendMessage(sock, "LIST|GROUPS|-");
            }
            else if (cmd == "private") {
                size_t split = args.find(' ');
                if (split != std::string::npos) {
                    std::string to = args.substr(0, split);
                    std::string msg = args.substr(split + 1);
                    SendMessage(sock, "PRIVATE|" + to + "|" + msg);
                }
                else {
                    std::cout << "[Error]: Please provide user and message, e.g.: /private username message" << std::endl;
                }
            }
            else if (cmd == "group") {
                size_t split = args.find(' ');
                if (split != std::string::npos) {
                    std::string group = args.substr(0, split);
                    std::string msg = args.substr(split + 1);

                    // 检查用户是否在群组中
                    if (std::find(clientState.joinedGroups.begin(),
                        clientState.joinedGroups.end(), group) != clientState.joinedGroups.end()) {
                        SendMessage(sock, "GROUP|" + group + "|" + msg);
                    }
                    else {
                        std::cout << "[Error]: You're not in this group, cannot send messages" << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: Please provide group and message, e.g.: /group groupname message" << std::endl;
                }
            }
            else if (cmd == "public") {
                if (!args.empty()) {
                    SendMessage(sock, "PUBLIC|-|" + args);
                }
                else {
                    std::cout << "[Error]: Please provide message content, e.g.: /public message" << std::endl;
                }
            }
            else if (cmd == "exit") {
                std::cout << "[System]: Exiting...\n";
                isRunning = false;  // 通知接收线程退出
                shutdown(sock, SD_BOTH);
                closesocket(sock);
                break;  // 跳出 HandleInput 循环
}
            else if (cmd == "help" || cmd == "?") {
                PrintHelp();
            }
            else {
            std::cout << "Unknown command, type /help for assistance" << std::endl;
            }
        }
        else {
            // 显示错误提示，不再自动发送消息
            std::cout << "[Error]: Messages must start with a command. Use /public <message> to send public message, or type /help for all commands." << std::endl;
        }
    }
}

int main() {
    WSADATA wsaData;
    SOCKET connectSock = INVALID_SOCKET;
    sockaddr_in serverAddr{};

    char ipStr[64];
    char portStr[16];
    std::cout << "Enter server IP address (e.g. 192.168.0.101): ";
    std::cin.getline(ipStr, sizeof(ipStr));
    std::cout << "Enter port number (default 5000, press Enter to use default): ";
    std::cin.getline(portStr, sizeof(portStr));
    int port = (strlen(portStr) > 0) ? atoi(portStr) : 5000;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup 失败: " << WSAGetLastError() << std::endl;
        return 1;
    }

    connectSock = socket(AF_INET, SOCK_STREAM, 0);
    if (connectSock == INVALID_SOCKET) {
        std::cerr << "创建套接字失败: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ipStr, &serverAddr.sin_addr) <= 0) {
        std::cerr << "IP 地址解析失败: " << ipStr << std::endl;
        closesocket(connectSock);
        WSACleanup();
        return 1;
    }

    if (connect(connectSock, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "连接服务器失败: " << WSAGetLastError() << std::endl;
        closesocket(connectSock);
        WSACleanup();
        return 1;
    }

    std::cout << "[Success] Connected to server " << ipStr << ":" << port << std::endl;
    des_init(0);
    des_set_key((char*)"mykey12");

    std::thread recvThread(MessageReceiver, connectSock);
    HandleInput(connectSock);  // 主线程负责输入
    recvThread.join();

    closesocket(connectSock);
    des_done();
    WSACleanup();
    std::cout << "[Client]: Disconnected, program will exit.\n";
    return 0;
}
