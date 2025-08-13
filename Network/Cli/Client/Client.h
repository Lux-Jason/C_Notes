#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "DES_c.h" 
constexpr int DEFAULT_PORT = 5000;
constexpr int BUFFER_SIZE = 1024;
void MessageReceiver(SOCKET sock);
void SendMessage(SOCKET sock, const std::string& msg);
void PrintHelp();
void HandleInput(SOCKET sock);
