//
// Created by stav on 1/11/19.
//

#ifndef PROJ2_CLIENTTESTHENDLER_H
#define PROJ2_CLIENTTESTHENDLER_H
#define END "end"
#include <vector>
#include <memory>
#include "ClientHendler.h"
#include "../Solver/Solver.h"
#include "../CacheManager/FileCacheManager.h"
#include "../Solver/AStar.h"
class MyClientTestHendler: public ClientHendler{
  shared_ptr<Solver<MatrixSearchable,MatrixSolution>> solver;
 public:
  MyClientTestHendler(){
      //inject facories, cache manager
      shared_ptr<MatrixSearchableFactory> matrixSerachableFactory=make_shared<MatrixSearchableFactory>();
      shared_ptr<MatrixSolutionFactory> solFactory=make_shared<MatrixSolutionFactory>();
      string searchableMatrixName=typeid(MatrixSearchable).name();
      string matrixSolutionName=typeid(MatrixSolution).name();
      shared_ptr<CacheManager<MatrixSearchable,MatrixSolution>> cacheManager
          = make_shared<FileCacheManager<MatrixSearchable,MatrixSolution>> (searchableMatrixName,
                                                                            matrixSerachableFactory,matrixSolutionName,solFactory);
      shared_ptr<Searcher<MatrixSearchable, MatrixSolution>>  aStar =make_shared<AStar>();
      solver= make_shared<Solver<MatrixSearchable,MatrixSolution>>
          (cacheManager,aStar);
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
#endif //PROJ2_CLIENTTESTHENDLER_H
