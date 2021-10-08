#ifndef RES_TP1_TERMINAL_H
#define RES_TP1_TERMINAL_H

#include <stdio.h>
#include "UDPConnection.h"
#include "network.h"


//Contient le socket d'écoute pour accepter les clients

class terminal {
public:
	terminal();
	void ListenInputTCP(TCPConnection connection);
	void ListenInputUDP(UDPConnection connection, int port, char* adresse);
private:
	SOCKET clientSocket = INVALID_SOCKET;
};

#endif //RES_TP1_TERMINAL_H
