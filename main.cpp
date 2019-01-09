
#include "ServerNameSpace/Servers/MySerialServer.h"
#include "ServerNameSpace/CacheManager/FileCacheManager.h"
#include "ServerNameSpace/Solver/StringReverserSearcher.h"
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

  return 0;
}