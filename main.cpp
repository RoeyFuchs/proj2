

#include "Tests/FileCacheManagerTests.h"
#include "ServerNameSpace/Solver/BFS.h"
#include <memory.h>
#include <vector>
int main() {
   // RunTests();


    vector<string> a;
    a.push_back("5");
    a.push_back("0,0");
    a.push_back("4,4");
    a.push_back("5, 1000 , 5 , 3 , 4");
    a.push_back("4, 0 , 500 , 300 , 500");
    a.push_back("0, 1 , 5 , 3 , 4");
    a.push_back("0, 10 , 5 , 3 , 4");
    a.push_back("0, 1 , 5 , 3 , 4");
    MatrixSearchable* matrixSearchable = new MatrixSearchable(a);
    BFS* bfs = new BFS(matrixSearchable);
    string sosol = bfs->Search(*matrixSearchable);
std::cout << sosol <<endl;
    return 0;
}