#include "Client.h"


int main() {
    WSADATA wsaData;
    SOCKET connectSock = INVALID_SOCKET;
    sockaddr_in serverAddr{};

    char ipStr[64];
    char portStr[16];
    std::cout << "Please enter the server IP address (e.g., 192.168.0.101): ";
    std::cin.getline(ipStr, sizeof(ipStr));
    std::cout << "Please enter the port number (default 5000, press Enter directly): ";
    std::cin.getline(portStr, sizeof(portStr));
    int port = (strlen(portStr) > 0) ? atoi(portStr) : 5000;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed: " << WSAGetLastError() << std::endl;
        return 1;
    }

    connectSock = socket(AF_INET, SOCK_STREAM, 0);
    if (connectSock == INVALID_SOCKET) {
        std::cerr << "Failed to create socket: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ipStr, &serverAddr.sin_addr) <= 0) {
        std::cerr << "Failed to parse IP address: " << ipStr << std::endl;
        closesocket(connectSock);
        WSACleanup();
        return 1;
    }

    if (connect(connectSock, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Failed to connect to the server: " << WSAGetLastError() << std::endl;
        closesocket(connectSock);
        WSACleanup();
        return 1;
    }

    std::cout << "[Connection successful] Connected to the server " << ipStr << ":" << port << std::endl;
    des_init(0);
    des_set_key((char*)"mykey12");

    std::thread recvThread(MessageReceiver, connectSock);
    HandleInput(connectSock);  // The main thread is responsible for input
    recvThread.join();

    closesocket(connectSock);
    des_done();
    WSACleanup();
    std::cout << "[Client]: Disconnected, the program is about to exit.\n";
    return 0;
}