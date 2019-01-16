//
// Created by stav on 1/16/19.
//

#ifndef PROJ2_MYTESTCLIENTHENDLER_H
#define PROJ2_MYTESTCLIENTHENDLER_H
#define END "end"
#include <vector>
#include <memory>
#include "ClientHendler.h"
#include "../Solver/Solver.h"
#include "../CacheManager/FileCacheManager.h"
#include "../Solver/StringReverserSearcher.h"
#include "../Factory/StringSearchableFactory.h"
#include "../Factory/StringSolutionFactory.h"
#define PATH "stringCache.txt"
class MyTestClientHendler: public ClientHendler{
  shared_ptr<Solver<MatrixSearchable,MatrixSolution>> solver;
 public:
  MyTestClientHendler(){
      //inject facories, cache manager
      shared_ptr<StringSearchableFactory> seaFactory=make_shared<StringSearchableFactory>();
      shared_ptr<StringSolutionFactory> solFactory=make_shared<StringSolutionFactory>();
      string searchableName=typeid(StringReverserSearchable).name();
      string solutionName=typeid(StringReverserSolution).name();
      shared_ptr<CacheManager<StringReverserSearchable,StringReverserSolution>> cacheManager
          = make_shared<FileCacheManager<StringReverserSearchable,StringReverserSolution>> (searchableName,
                                                                            seaFactory,solutionName,solFactory,PATH);
      shared_ptr<StringReverserSearcher>  stringReverser =
          make_shared<StringReverserSearcher>();
      solver= make_shared<Solver<MatrixSearchable,MatrixSolution>>
          (cacheManager,stringReverser);
  }
  /**
   * HandleClient
   * @param inputStream
   * @param outputStream
   * The function gets  an input stream, read a problem and resove it
   */
  virtual void HandleClient(InputStream& inputStream, OutputStream& outputStream){
      string line;
      vector<string> vec;
      inputStream>>line;
      //run untill the end of problem
      while (line!= END){
          cout<<line<<endl;
          vec.push_back(line);
          inputStream>>line;
      }

      shared_ptr<MatrixSearchable> matrixSerachable= make_shared<MatrixSearchable>(vec);
      string solution= solver->Solve(matrixSerachable)->ToString();
      outputStream<<solution;
  }
};
#endif //PROJ2_CLIENTTESTHE
#endif //PROJ2_MYTESTCLIENTHENDLER_H
