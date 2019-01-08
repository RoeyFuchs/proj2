#include <iostream>
#include "ServerNameSpace/Servers/MySerialServer.h"
#include "ServerNameSpace/Solver/Searchable.h"
#include "ServerNameSpace/Solver/Searcher.h"
#include "ServerNameSpace/Solver/StringReverserSearchable.h"
#include "ServerNameSpace/Solver/StringReverserSearcher.h"
#include "ServerNameSpace/CacheManager/CacheManager.h"
#include "ServerNameSpace/CacheManager/FileCacheManager.h"
#include <memory.h>
#include <vector>
#include "ServerNameSpace/Utils/Utils.h"
int main() {
    /*vector<string> vec= {"abcsdef"};
    shared_ptr<Searchable<string>> stringProblem =make_shared<StringReverserSearchable>(vec);
    cout<<stringProblem->GetInitialState().GetState()<<endl;
    StringReverserSearcher stringAlgo;
    shared_ptr<Solution<string>> stringSol= stringAlgo.Search(stringProblem);
    cout<< stringSol->ToString()<<endl;
    StringReverserSolution* st= new StringReverserSolution(vec);
    shared_ptr<CacheManager<string,string>> cacheManager= make_shared<FileCacheManager<string,string>>();
   // cacheManager->AddSolution(stringProblem,stringSol);
           //* make_shared<FileCacheManager<StringReverserSearchable,StringReverserSolution>>();*/


    return 0;
}