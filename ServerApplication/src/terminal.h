//
// Created by nicol on 01/10/2021.
//

#include <WinSock2.h>
#include <winsock.h>
#include <stdio.h>
#include "network.h"
#ifndef RES_TP1_TERMINAL_H
#define RES_TP1_TERMINAL_H

#include "network.h"

//Contient le socket d'�coute pour accepter les clients
class terminal  : public network {

class terminal : public network {
private:
	SOCKET clientSocket = INVALID_SOCKET;
public:
	terminal();
};


#endif //RES_TP1_TERMINAL_H
