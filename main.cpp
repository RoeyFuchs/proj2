#include "Proj2/ClientHendlers/MyClientHendler.h"
#include "Proj2/Servers/MyParallelServer.h"
#include "Proj2/ClientHendlers/ClientHendler.h"
#include "Proj2/ClientHendlers/MyClientHendler.h"
#include <memory.h>
#include <vector>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        exit(1);
    }
    shared_ptr<ClientHendler>clientHendler = make_shared<MyClientHendler>();
    shared_ptr<MyParallelServer> server = make_shared<MyParallelServer>();
    server->Open(stoi(argv[1]), clientHendler.get());
    server->Start();
    server->Stop();

    return 0;
}