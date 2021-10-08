#ifndef RES_TP1_UDPCONNECTION_H
#define RES_TP1_UDPCONNECTION_H

#include "connection.h"

class UDPConnection : public Connection {
public:
    UDPConnection(SOCKET listenSocket, SOCKET connectSocket);
    void Receive();
    void Send(char* message);
private:
};

#endif //RES_TP1_UDPCONNECTION_H
