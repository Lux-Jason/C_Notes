//Client.cpp
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "Client.h" 
#pragma comment(lib, "ws2_32.lib")

// Atomic boolean variable to control the program running state
std::atomic<bool> isRunning(true);

// Client state information structure
struct ClientState {
    // Username
    std::string username;
    // List of joined groups
    std::vector<std::string> joinedGroups;
    // List of groups created by the user
    std::vector<std::string> ownedGroups;
} clientState;

// Print help information
void PrintHelp() {
    std::cout << "\nAvailable commands:\n"
        << "/login <username>        - Log in/change nickname\n"
        << "/create <groupname>      - Create a new group\n"
        << "/kick <groupname> <username> - The group owner kicks a user\n"
        << "/disband <groupname>     - The group owner disbands the group\n"
        << "/mute <groupname> <username> - The group owner mutes a group member\n"
        << "/unmute <groupname> <username> - The group owner unmutes a group member\n"
        << "/join <groupname>        - Join a group\n"
        << "/leave <groupname>       - Leave a group\n"
        << "/members <groupname>     - View group members\n"
        << "/muted <groupname>       - View muted users\n"
        << "/list                    - List online users\n"
        << "/listgroups              - List all available groups\n"
        << "/private <user> <message> - Send a private message\n"
        << "/group <group> <message> - Send a group message\n"
        << "/public <message>        - Send a broadcast message\n"
        << "/exit                    - Exit the program\n"
        << "/deleteuser <username>   - [admin only] Delete a user from system\n"
        << "/assign <group> <username> - [admin only] Assign user to group\n"
        << "/help                    - Display help\n";
}

// -------- Client receiving thread: Support length header + DES unpacking --------
void MessageReceiver(SOCKET sock)
{
    std::vector<char> inBuf;               // Raw receiving buffer
    std::vector<char> plainBuf;            // Decrypted plaintext
    char tmp[BUFFER_SIZE];

    auto needMore = [&](void) -> bool {
        int n = recv(sock, tmp, BUFFER_SIZE, 0);
        if (n <= 0) {
            if (n == 0) {
                std::cerr << "\n[System prompt]: The server has been closed, and the connection is disconnected.\n";
            }
            else {
                std::cerr << "\n[System prompt]: Failed to receive data, error code: " << WSAGetLastError() << std::endl;
            }
            isRunning = false;
            return false;
        }

        inBuf.insert(inBuf.end(), tmp, tmp + n);
        return true;
        };

    while (isRunning)
    {
        /*------------------- ① Parse the 4-byte plaintext length header -------------------*/
        while (inBuf.size() < 4 && needMore()) {}
        if (inBuf.size() < 4) break;       // Disconnected

        uint32_t L;
        memcpy(&L, inBuf.data(), 4);
        L = ntohl(L);                      // Plaintext length

        /*------------------- ② Calculate the required encrypted byte count -------------------*/
        size_t pad = 8 - (L % 8);
        if (pad == 0) pad = 8;
        size_t encLen = L + pad;           // Total ciphertext length

        /*------------------- ③ Receive the entire ciphertext -------------------*/
        while (inBuf.size() < 4 + encLen && needMore()) {}
        if (inBuf.size() < 4 + encLen) break;   // Disconnected

        /*------------------- ④ Decrypt the entire message -------------------*/
        plainBuf.clear();
        for (size_t off = 4; off < 4 + encLen; off += 8) {
            char blk[8];
            memcpy(blk, inBuf.data() + off, 8);
            des_decrypt(blk);
            plainBuf.insert(plainBuf.end(), blk, blk + 8);
        }
        inBuf.erase(inBuf.begin(), inBuf.begin() + 4 + encLen); // Remove the processed bytes

        /*------------------- ⑤ Remove PKCS#7 padding -------------------*/
        if (plainBuf.empty()) continue;    // Defensive check
        size_t realLen = plainBuf.size() - static_cast<unsigned char>(plainBuf.back());
        if (realLen > plainBuf.size()) continue; // Padding exception, ignore
        std::string msg(plainBuf.data(), realLen);

        /*------------------- ⑥ Parse the "TYPE|FROM|CONTENT" protocol -------------------*/
        size_t p1 = msg.find('|');
        size_t p2 = msg.find('|', p1 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        std::string type = msg.substr(0, p1);
        std::string from = msg.substr(p1 + 1, p2 - p1 - 1);
        std::string content = msg.substr(p2 + 1);

        if (type == "PRIVATE") {
            std::cout << "\n[Private message from " << from << "]: " << content << std::endl;
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
            std::cout << "\nList of online users:\n" << content << std::endl;
        }
        else if (type == "GROUPS") {
            std::replace(content.begin(), content.end(), ',', '\n');
            std::cout << "\nList of available groups:\n" << content << std::endl;
        }
        else if (type == "LOGIN") {
            std::cout << "\n[Login successful]: " << content << std::endl;
            clientState.username = content;
        }
        else if (type == "CREATE") {
            std::cout << "\n[Group creation successful]: " << content << std::endl;
            clientState.ownedGroups.push_back(content);
            clientState.joinedGroups.push_back(content);
        }
        else if (type == "JOIN") {
            std::cout << "\n[Joined group successfully]: " << content << std::endl;
            if (std::find(clientState.joinedGroups.begin(),
                clientState.joinedGroups.end(), content) == clientState.joinedGroups.end()) {
                clientState.joinedGroups.push_back(content);
            }
        }
        else if (type == "LEAVE") {
            std::cout << "\n[Left group successfully]: " << content << std::endl;
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

        std::cout << "Enter a command (? for help): ";
        std::cout.flush();
    }
}

void SendMessage(SOCKET sock, const std::string& msg) {
    // --- 1. PKCS#7 padding ---
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

    // --- 3. Send with a 4-byte length header ---
    uint32_t L = htonl(static_cast<uint32_t>(msg.size()));  // Plaintext length
    send(sock, reinterpret_cast<char*>(&L), 4, 0);
    send(sock, enc.data(), static_cast<int>(enc.size()), 0);
}

void HandleInput(SOCKET sock) {
    std::string input;
    PrintHelp();

    while (isRunning) {
        std::cout << "Enter a command (? for help): ";
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
                    std::cout << "[Error]: Please provide a username, e.g., /login username" << std::endl;
                }
            }
            else if (cmd == "create") {
                if (!args.empty()) {
                    SendMessage(sock, "CREATE|" + args + "|-");
                }
                else {
                    std::cout << "[Error]: Please provide a group name, e.g., /create groupname" << std::endl;
                }
            }
            else if (cmd == "kick") {
                // Parse the group name and username
                size_t split = args.find(' ');
                if (split != std::string::npos) {
                    std::string group = args.substr(0, split);
                    std::string user = args.substr(split + 1);

                    // Check if the current user is the group owner
                    if (std::find(clientState.ownedGroups.begin(),
                        clientState.ownedGroups.end(), group) != clientState.ownedGroups.end()) {
                        SendMessage(sock, "KICK|" + group + "|" + user);
                    }
                    else {
                        std::cout << "[Error]: You are not the group owner and cannot kick users." << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: Please correctly provide the group name and username, e.g., /kick groupname username" << std::endl;
                }
            }
            else if (cmd == "disband") {
                if (!args.empty()) {
                    // Check if the current user is the group owner
                    if (std::find(clientState.ownedGroups.begin(),
                        clientState.ownedGroups.end(), args) != clientState.ownedGroups.end()) {
                        SendMessage(sock, "DISBAND|" + args + "|-");

                        // Locally clear group information
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
                        std::cout << "[Error]: You are not the group owner and cannot disband the group." << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: Please provide a group name, e.g., /disband groupname" << std::endl;
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
                    // Check if the user is in the group
                    if (std::find(clientState.joinedGroups.begin(),
                        clientState.joinedGroups.end(), args) != clientState.joinedGroups.end()) {
                        SendMessage(sock, "MUTED|" + args + "|-");
                    }
                    else {
                        std::cout << "[Error]: You are not in the group and cannot view muted members." << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: The format is /muted groupname" << std::endl;
                }
            }
            else if (cmd == "deleteuser") {
                if (!args.empty()) {
                    SendMessage(sock, "DELETEUSER|" + args + "|-");
                }
                else {
                    std::cout << "[Error]: Usage is /deleteuser username\n";
                }
            }
            else if (cmd == "members") {
                if (!args.empty()) {
                    // Check if the user is in the group
                    if (std::find(clientState.joinedGroups.begin(),
                        clientState.joinedGroups.end(), args) != clientState.joinedGroups.end()) {
                        SendMessage(sock, "MEMBERS|" + args + "|-");
                    }
                    else {
                        std::cout << "[Error]: You are not in the group and cannot view members." << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: Please provide a group name, e.g., /members groupname" << std::endl;
                }
            }
            else if (cmd == "join") {
                if (!args.empty()) {
                    SendMessage(sock, "JOIN|" + args + "|-");
                }
                else {
                    std::cout << "[Error]: Please provide a group name, e.g., /join groupname" << std::endl;
                }
            }
            else if (cmd == "leave") {
                if (!args.empty()) {
                    SendMessage(sock, "LEAVE|" + args + "|-");
                }
                else {
                    std::cout << "[Error]: Please provide a group name, e.g., /leave groupname" << std::endl;
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
                    std::cout << "[Error]: Please correctly provide the username and message, e.g., /private username message" << std::endl;
                }
            }
            else if (cmd == "assign") {
                size_t split = args.find(' ');
                if (split != std::string::npos) {
                    std::string group = args.substr(0, split);
                    std::string user = args.substr(split + 1);
                    SendMessage(sock, "ASSIGN|" + group + "|" + user);
                }
                else {
                    std::cout << "[Error]: Usage: /assign groupname username\n";
                }
            }

            else if (cmd == "group") {
                size_t split = args.find(' ');
                if (split != std::string::npos) {
                    std::string group = args.substr(0, split);
                    std::string msg = args.substr(split + 1);

                    // Check if the user is in the group
                    if (std::find(clientState.joinedGroups.begin(),
                        clientState.joinedGroups.end(), group) != clientState.joinedGroups.end()) {
                        SendMessage(sock, "GROUP|" + group + "|" + msg);
                    }
                    else {
                        std::cout << "[Error]: You are not in the group and cannot send messages." << std::endl;
                    }
                }
                else {
                    std::cout << "[Error]: Please correctly provide the group name and message, e.g., /group groupname message" << std::endl;
                }
            }
            else if (cmd == "public") {
                if (!args.empty()) {
                    SendMessage(sock, "PUBLIC|-|" + args);
                }
                else {
                    std::cout << "[Error]: Please provide the message content, e.g., /public message" << std::endl;
                }
            }
            else if (cmd == "exit") {
                std::cout << "[System]: Exiting...\n";
                isRunning = false;  // Notify the receiving thread to exit
                shutdown(sock, SD_BOTH);
                closesocket(sock);
                break;  // Break out of the HandleInput loop
            }
            else if (cmd == "help" || cmd == "?") {
                PrintHelp();
            }
            else {
                std::cout << "Unknown command. Enter /help to view help." << std::endl;
            }

        }
        else {
            // Display an error prompt, no longer automatically send messages
            std::cout << "[Error]: Messages must start with a command. Use /public <message> to send a public message, or enter /help to view all commands." << std::endl;
        }
    }
}
