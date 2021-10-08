#include <WS2tcpip.h>
#include <stdio.h>

#include "terminal.h"
#include "connection.h"
#include "TCPConnection.h"

#pragma comment(lib, "Ws2_32.lib")

//#define DEFAULT_BUFLEN 512

#ifndef RES_TP1_NETWORK_H
#define RES_TP1_NETWORK_H


#include <string>


class network {
public:
	network(int protocol, std::string ipAdress, int port);
	void Connect(addrinfo* result, int port, char* adresse);
	void ListenServer(TCPConnection connection);
	SOCKET getListenSocket() { return listenSocket; };
private:
	SOCKET listenSocket = INVALID_SOCKET;
	fd_set socketList;

};


#endif //RES_TP1_NETWORK_H
