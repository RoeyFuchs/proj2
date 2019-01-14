

#include "ServerNameSpace/Solver/Solver.h"
#include "ServerNameSpace/Solver/BFS.h"
#include "ServerNameSpace/Solver/DFS.h"
#include "ServerNameSpace/Solver/AStar.h"
#include "ServerNameSpace/Solver/BreadthFirst.h"
#include "ServerNameSpace/CacheManager/FileCacheManager.h"
#include <memory.h>
#include <vector>
int main() {
    //RunTests();
    vector<string> a;
    a.push_back("5, 1 ,0 ,1 ,1");
    a.push_back("4, 300 ,500 ,300 ,0");
    a.push_back("1, 1 ,5 ,3 , 500");
    a.push_back("100, 10, 50 , 1 , 10");
    a.push_back("1, 1 , 5 , 10 , 4");
    a.push_back("0,0");
    a.push_back("4,4");
    shared_ptr<MatrixSearchable> matrixSearchable = make_shared< MatrixSearchable>(a);
    shared_ptr<Searcher<shared_ptr<MatrixSearchable>, shared_ptr<MatrixSolution>>>dfs =make_shared<DFS>();
    shared_ptr<Solution<int>> dfsSol; /*= dfs->Search(matrixSearchable);*/


    shared_ptr<SearchableFactory<MatrixSearchable>> matrixSerachableFactory=make_shared<MatrixSearchableFactory>();
    shared_ptr<SolutionFactory<int>> solFactory=make_shared<MatrixSolutionFactory>();
    vector<string> vec;
    string searchableMatrixName=typeid(MatrixSearchable).name();
    string matrixSolutionName=typeid(MatrixSolution).name();

    shared_ptr<CacheManager<MatrixSearchable,MatrixSolution>> cacheManager
        = make_shared<FileCacheManager<MatrixSearchable,MatrixSolution>>(searchableMatrixName,
                                                               matrixSerachableFactory,matrixSolutionName,solFactory);

    shared_ptr<Solver<MatrixSearchable,MatrixSolution>> solver= make_shared<Solver<MatrixSearchable,MatrixSolution>>
        (cacheManager,dfs);
  /*   shared_ptr<Searchable<shared_ptr<Point>>> matrixSearchable = make_shared< MatrixSearchable>(a);
     shared_ptr<Searcher<shared_ptr<Searchable<shared_ptr<Point>>>, shared_ptr<Solution<int>>>>dfs =make_shared<DFS>();
     shared_ptr<Solution<int>> dfsSol; /*= dfs->Search(matrixSearchable);


    shared_ptr<SearchableFactory<shared_ptr<Point>>> matrixSerachableFactory=make_shared<MatrixSearchableFactory>();
    shared_ptr<SolutionFactory<int>> solFactory=make_shared<MatrixSolutionFactory>();
     vector<string> vec;
     string searchableMatrixName=typeid(MatrixSearchable).name();
     string matrixSolutionName=typeid(MatrixSolution).name();

     shared_ptr<CacheManager<shared_ptr<Point>,int>> cacheManager
     = make_shared<FileCacheManager<shared_ptr<Point>,int>>(searchableMatrixName,
        matrixSerachableFactory,matrixSolutionName,solFactory);

    shared_ptr<Solver<shared_ptr<Point>,int>> solver= make_shared<Solver<shared_ptr<Point>,int>>
     (cacheManager,dfs);*/
  //  dfsSol= solver->Solve(matrixSearchable);
   // std::cout<<dfsSol->ToString()<<endl;


/*    vector<string> a;
    a.push_back("5, 1 ,0 ,1 ,1");
    a.push_back("4, 300 ,500 ,300 ,0");
    a.push_back("1, 1 ,5 ,3 , 500");
    a.push_back("100, 10, 50 , 1 , 10");
    a.push_back("1, 1 , 5 , 10 , 4");
    a.push_back("0,0");
    a.push_back("4,4");
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