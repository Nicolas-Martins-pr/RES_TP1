#ifndef RES_TP1_TERMINAL_H
#define RES_TP1_TERMINAL_H

#include <stdio.h>
#include "network.h"
#include "TCPConnection.h"

//Contient le socket d'écoute pour accepter les clients

class terminal {
public:
	terminal(SOCKET listenSocket);
private:
	SOCKET clientSocketUDP = INVALID_SOCKET;
	SOCKET clientSocketTCP = INVALID_SOCKET;
};

#endif //RES_TP1_TERMINAL_H
