#include <iostream>
#include "ServerNameSpace/Servers/MySerialServer.h"
int main() {
  MySerialServer* ms = new MySerialServer();
  ms->Open(5400);
  std::cout<< "check"<<std::endl;
  ms->Start();
  return 0;
}