//
// Created by nicol on 01/10/2021.
//

#include <winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>

#include "terminal.h"
#include "connection.h"

#pragma comment(lib, "Ws2_32.lib")

//#define DEFAULT_BUFLEN 512

#ifndef RES_TP1_NETWORK_H
#define RES_TP1_NETWORK_H


class network {
public:
	network(char* ipAdress, char* port);
	void Listen();
	void Connect();
	void Update();
private:
	SOCKET listenSocketUDP = INVALID_SOCKET;
	SOCKET listenSocketTCP = INVALID_SOCKET;

};


#endif //RES_TP1_NETWORK_H
