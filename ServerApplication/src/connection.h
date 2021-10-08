//
// Created by nicol on 01/10/2021.
//

#include <winsock2.h>
#include <WS2tcpip.h>
#include <cstdio>

#ifndef RES_TP1_CONNECTION_H
#define RES_TP1_CONNECTION_H

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512

class Connection {

public:
    Connection(SOCKET listenSocket, SOCKET connectSocket);
    void Receive();
    void Send();
    SOCKET getConnectSocket() { return connectSocket;};
    SOCKET getServerSocket() { return serverSocket;};

private:
    SOCKET connectSocket = INVALID_SOCKET;
    SOCKET serverSocket = INVALID_SOCKET;
};

#endif //RES_TP1_CONNECTION_H
