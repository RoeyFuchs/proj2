

#include "Tests/FileCacheManagerTests.h"
#include "ServerNameSpace/Solver/BFS.h"
#include <memory.h>
#include <vector>
int main() {
    RunTests();


   vector<string> a;
    a.push_back("5");
    a.push_back("0,0");
    a.push_back("4,4");
    a.push_back("5, 1 ,0 ,1 ,1");
    a.push_back("4, 300 ,500 ,300 ,0");
    a.push_back("1, 1 ,5 ,3 , 0");
    a.push_back("1, 10, 50 , -1 , -1");
    a.push_back("1, 1 , 5 , 1 , 4");
    MatrixSearchable* matrixSearchable = new MatrixSearchable(a);
    BFS* bfs = new BFS(matrixSearchable);
    string sosol = bfs->Search(*matrixSearchable);
    delete bfs;
    delete matrixSearchable;
std::cout << sosol <<endl;
    return 0;
}