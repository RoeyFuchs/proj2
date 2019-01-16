
#include "ServerNameSpace/ClientHendlers/MyClientTestHendler.h"
#include "Tests/MatrixCreator.h"
#include "Tests/CompareAlgos.h"
#include "ServerNameSpace/Servers/MyParallelServer.h"
#include <memory.h>
#include <vector>
int main(int argc, char *argv[]) {

    /*if (argc != 2) {
        exit(1);
    }
    shared_ptr<ClientHendler>clientHendler = make_shared<MyClientTestHendler>();
    shared_ptr<MyParallelServer> server = make_shared<MyParallelServer>();
    server->Open(stoi(argv[1]), clientHendler.get());
    server->Start();
    server->Stop();*/


    Run();


    return 0;
}