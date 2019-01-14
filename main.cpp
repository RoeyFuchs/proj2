

#include "Tests/FileCacheManagerTests.h"
#include "Tests/MatrixCreator.h"
#include "ServerNameSpace/Solver/BFS.h"
#include "ServerNameSpace/Solver/AStar.h"
#include "ServerNameSpace/Solver/BreadthFirst.h"
#include <memory.h>
#include <vector>
#include <zconf.h>
int main() {
    //RunTests();


    /*vector<string> vec;
    shared_ptr<FileCacheManager<shared_ptr<Point>,int>> cacheManager
    = make_shared<FileCacheManager<shared_ptr<Point>,int>>();*/
for(int i = 0 ; i < 2; ++i) {
    auto mat = Create(10, 10, 0.1);
    AStar *aStar = new AStar(mat);
    std::string sol = aStar->Search(*mat);
    printMat(mat);
    cout << sol << endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(500));
}
    /*vector<string> a;
    a.push_back("5");
    a.push_back("0,0");
    a.push_back("4,4");
    a.push_back("5, 1 ,0 ,1 ,1");
    a.push_back("4, 300 ,500 ,300 ,0");
    a.push_back("1, 1 ,5 ,3 , 500");
    a.push_back("100, 10, 50 , 1 , 10");
    a.push_back("1, 1 , 5 , 10 , 4");
    MatrixSearchable *matrixSearchable = new MatrixSearchable(a);
    AStar *aStar = new AStar(matrixSearchable);
    BFS *bfs = new BFS(matrixSearchable);
    BreadthFirst* breadthFirst = new BreadthFirst(matrixSearchable);
    string aStarsol = aStar->Search(*matrixSearchable);
    string bfsrsol = bfs->Search(*matrixSearchable);
    string breadthFirstrsol = breadthFirst->Search(*matrixSearchable);
    delete aStar;
    delete matrixSearchable;
    delete bfs;
    std::cout << aStarsol << endl;
    std::cout << bfsrsol << endl;
    std::cout << breadthFirstrsol << endl;*/
    return 0;
}