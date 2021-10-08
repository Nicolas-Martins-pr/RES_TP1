#ifndef RES_TP1_UDPCONNECTION_H
#define RES_TP1_UDPCONNECTION_H

#include "connection.h"

class UDPConnection : public Connection {
public:
    UDPConnection(SOCKET listenSocket, sockaddr ipAddr);
    void Receive();
    void Send(char* message, int port, char* adresse);
private:
    sockaddr targetIP;
};

#endif //RES_TP1_UDPCONNECTION_H
