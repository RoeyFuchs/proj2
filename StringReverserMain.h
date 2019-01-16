//
// Created by stav on 1/16/19.
//

#ifndef PROJ2_STRINGREVERSERMAIN_H
#define PROJ2_STRINGREVERSERMAIN_H
#include <memory>
#include <vector>
#include <cstdlib>
#include "ServerNameSpace/ClientHendlers/ClientHendler.h"
#include "ServerNameSpace/Servers/MySerialServer.h"
#include "ServerNameSpace/ClientHendlers/MyTestClientHendler.h"
namespace boot {
class Main {
  int main(int argc, char *argv[]) {
      if (argc != 2) {
          exit(1);
      }
      shared_ptr<ClientHendler> clientHendler = make_shared<MyTestClientHendler>();
      shared_ptr<MySerialServer> server = make_shared<MySerialServer>();
      server->Open(stoi(argv[1]), clientHendler.get());
      server->Start();
      server->Stop();
  }
};
}

#endif //PROJ2_STRINGREVERSERMAIN_H
