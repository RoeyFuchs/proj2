//
// Created by stav on 1/2/19.
//

#ifndef PROJ2_SERVER_H
#define PROJ2_SERVER_H

#include "ClientHendlers/ClientHendler.h"

class Server {
  virtual void Open(int port, ClientHendler* clientHendler) = 0;
  virtual void Stop() = 0;
};

#endif //PROJ2_SERVER_H
