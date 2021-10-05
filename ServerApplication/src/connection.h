//
// Created by nicol on 01/10/2021.
//

#ifndef RES_TP1_CONNECTION_H
#define RES_TP1_CONNECTION_H

#include "network.h"

//Contient 1 socket client et 1 socket server
class Connection : public network {

private:
public:
    void Receive();
    void Rend();
};


#endif //RES_TP1_CONNECTION_H
