#pragma once
#include "DES_s.h"
using std::string;
using std::vector;

constexpr uint16_t DEFAULT_PORT = 5000;
constexpr size_t   BUFFER_SIZE = 1024;
void logEvent(const std::string& type, const std::string& message);
void safeSend(SOCKET s, const std::string& msg);
void handleClient(SOCKET clientSock, sockaddr_in addr);
void pruneDeadSocket(SOCKET deadSock);