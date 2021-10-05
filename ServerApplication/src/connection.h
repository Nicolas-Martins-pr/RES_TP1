//
// Created by nicol on 01/10/2021.
//

#include <winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>


#ifndef RES_TP1_CONNECTION_H
#define RES_TP1_CONNECTION_H

#include "network.h"

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_ADDR "localhost"

//Contient 1 socket client et 1 socket server
class Connection {

public:
    Connection();
    void Receive();
    void Send();

private:
    SOCKET clientSocket = INVALID_SOCKET;
    SOCKET serverSocket = INVALID_SOCKET;
};


#endif //RES_TP1_CONNECTION_H
