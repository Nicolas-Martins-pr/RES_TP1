//
// Created by nicol on 01/10/2021.
//

#ifndef RES_TP1_UDPCONNECTION_H
#define RES_TP1_UDPCONNECTION_H


#include "connection.h"

class UDPConnection : public Connection {
public:
	UDPConnection(SOCKET listenSocket);
    void Receive();
    void Send(char* message);
private:
};


#endif //RES_TP1_UDPCONNECTION_H
