//
// Created by stav on 1/2/19.
//

#ifndef PROJ2_CLIENTHENDLER_H
#define PROJ2_CLIENTHENDLER_H
using namespace std;
#include <istream>
#include <ostream>

class ClientHendler {
public:
    virtual void HandleClient(istream inputStream, ostream outputStream)=0;

};


#endif //PROJ2_CLIENTHENDLER_H
