

#include "ServerNameSpace/CacheManager/FileCacheManager.h"
#include "ServerNameSpace/Solver/StringReverserSearcher.h"
#include "ServerNameSpace/Solver/BFS.h"
#include <memory.h>
#include <vector>
int main() {
    /*vector<string> vec= {"abcsdef"};
    shared_ptr<Searchable<string>> stringProblem =make_shared<StringReverserSearchable>(vec);
    cout<<stringProblem->GetInitialState().GetState()<<endl;
    StringReverserSearcher stringAlgo;
    shared_ptr<Solution<string>> stringSol;*//*= stringAlgo.Search(stringProblem);*//*
 // cout<< stringSol->ToString()<<endl;
  shared_ptr<FileCacheManager<string,string>> cacheManager= make_shared<FileCacheManager<string,string>>();
 // cacheManager->AddSolution(stringProblem,stringSol);
  stringSol=cacheManager->GetSolution(stringProblem);
  cout<<stringSol->ToString()<<endl;
         *//* make_shared<FileCacheManager<StringReverserSearchable,StringReverserSolution>>();*/


    vector<string> a;
    a.push_back("5");
    a.push_back("0,0");
    a.push_back("4,4");
    a.push_back("5, 1 , 5 , 3 , 4");
    a.push_back("4, 0 , 500 , 300 , 4");
    a.push_back("0, 1 , 5 , 3 , 4");
    a.push_back("0, 1 , 5 , 3 , 4");
    a.push_back("0, 1 , 5 , 3 , 4");
    MatrixSearchable* matrixSearchable = new MatrixSearchable(a);
    BFS* bfs = new BFS(matrixSearchable);
    string sosol = bfs->Search(*matrixSearchable);
std::cout << sosol <<endl;
    return 0;
}