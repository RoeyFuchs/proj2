//
// Created by stav on 1/2/19.
//

#ifndef PROJ2_CLIENTHENDLER_H
#define PROJ2_CLIENTHENDLER_H
using namespace std;
#include <istream>
#include <ostream>
#include "../Stream/InputStream.h"
#include "../Stream/OutputStream.h"
#include "../Solver/Searcher.h"
#include <memory.h>
class ClientHendler {
public:
    virtual void HandleClient(InputStream inputStream, OutputStream outputStream)=0;

};


#endif //PROJ2_CLIENTHENDLER_H
