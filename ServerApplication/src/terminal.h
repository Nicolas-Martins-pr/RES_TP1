//
// Created by nicol on 01/10/2021.
//

#include <WinSock2.h>
#include <winsock.h>
#include <stdio.h>


#ifndef RES_TP1_TERMINAL_H
#define RES_TP1_TERMINAL_H

#include "network.h"

//Contient le socket d'écoute pour accepter les clients

class terminal {
public:
	terminal(SOCKET listenSocket);
private:
	SOCKET clientSocketTCP = INVALID_SOCKET;
};


#endif //RES_TP1_TERMINAL_H
