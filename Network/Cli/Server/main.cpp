#pragma once
#include "Server.h"


int main() {
    logEvent("SERVER", "=== Server Started ===");
    try {
        // Initialize DES encryption
        if (des_init(0) == 0) {
            fprintf(stderr, "DES initialization failed\n");
            return 1;
        }
        des_set_key((char*)"mykey12"); // Must be the same as the client key

        WSADATA ws;        if (WSAStartup(MAKEWORD(2, 2), &ws)) {
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