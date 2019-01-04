#include <iostream>
#include "ServerNameSpace/Servers/MySerialServer.h"
#include "ServerNameSpace/Solver/Searchable.h"
#include "ServerNameSpace/Solver/Searcher.h"
#include "ServerNameSpace/Solver/StringReverserSearchable.h"
#include "ServerNameSpace/Solver/StringReverserSearcher.h"
#include <memory.h>
int main() {
  shared_ptr<Searchable<string>> stringProblem =make_shared<StringReverserSearchable>("abcdef");
  cout<<stringProblem->GetInitialState().GetState()<<endl;
  shared_ptr<Searcher<string, string>> stringAlgo= make_shared<StringReverserSearcher>();
  cout<< stringAlgo->Search(stringProblem)<<endl;
  return 0;
}