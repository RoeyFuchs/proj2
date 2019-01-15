

#include "ServerNameSpace/ClientHendlers/MyClientTestHendler.h"
#include "Tests/MatrixCreator.h"
#include "Tests/CompareAlgos.h"
#include "ServerNameSpace/Servers/MyParallelServer.h"
#include <memory.h>
#include <vector>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        exit(1);
    }
    shared_ptr<ClientHendler>clientHendler = make_shared<MyClientTestHendler>();
    shared_ptr<MyParallelServer> server = make_shared<MyParallelServer>();
    server->Open(stoi(argv[1]), clientHendler.get());
    server->Start();
    server->Stop();





    // shared_ptr<MyClientTestHendler> client=make_shared<MyClientTestHendler>();
    //Run();

    /*vector<string> a;
    a.push_back("1,1,1,1,1");
    a.push_back("1, 1 , -1, 1,1");
    a.push_back("0,0");
    a.push_back("4,4");
    MatrixSearchable* mat =new  MatrixSearchable(a);
     BreadthFirst* breadthFirst = new BreadthFirst();
     breadthFirst->Search(*mat);*/


    //RunTests();
/*

    vector<string> a;
    a.push_back("5, 1 ,0 ,1 ,1");
    a.push_back("4, 300 ,500 ,300 ,0");
    a.push_back("1, 1 ,5 ,3 , 500");
    a.push_back("100, 10, 50 , 1 , 10");
    a.push_back("1, 1 , 5 , 10 , 4");
    a.push_back("0,0");
    a.push_back("4,4");
    shared_ptr<MatrixSearchableFactory> matrixSerachableFactory=make_shared<MatrixSearchableFactory>();
    shared_ptr<MatrixSolutionFactory> solFactory=make_shared<MatrixSolutionFactory>();
    vector<string> vec;
    string searchableMatrixName=typeid(MatrixSearchable).name();
    string matrixSolutionName=typeid(MatrixSolution).name();

    shared_ptr<CacheManager<MatrixSearchable,MatrixSolution>> cacheManager
        = make_shared<FileCacheManager<MatrixSearchable,MatrixSolution>> (searchableMatrixName,
                                                               matrixSerachableFactory,matrixSolutionName,solFactory);
   // shared_ptr<Searcher<shared_ptr<Searchable<shared_ptr<Point>>>, shared_ptr<MatrixSolution>>>
    shared_ptr<Searcher<MatrixSearchable, MatrixSolution>>  dfs =make_shared<DFS>();


   shared_ptr<Solver<MatrixSearchable,MatrixSolution>> solver= make_shared<Solver<MatrixSearchable,MatrixSolution>>
        (cacheManager,dfs);



   //Todo: transfer to client hendler
   shared_ptr<MatrixSearchable> matrixSerachable= make_shared<MatrixSearchable>(a);
        string solu= solver->Solve(matrixSerachable)->ToString();
        std::cout<<solu<<endl;
*/


    return 0;
}