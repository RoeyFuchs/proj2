//
// Created by stav on 1/2/19.
//

#ifndef PROJ2_SERVER_H
#define PROJ2_SERVER_H

#include "ClientHendler.h"

class Server {
    void Open (int port, ClientHendler* clientHendler);
    void Stop();
};


#endif //PROJ2_SERVER_H
