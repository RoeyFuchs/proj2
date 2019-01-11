//
// Created by stav on 1/11/19.
//

#ifndef PROJ2_MATRIXSOLUTIONFACTORY_H
#include "SolutionFactory.h"
#include "../Solver/MatrixSolution.h"
class MatrixSolutionFactory:public SolutionFactory<int>{
 public:
  virtual shared_ptr<Solution<int>> Create(vector<std::string> vec){
      return make_shared<MatrixSolution>(vec);
  }
};
#endif //PROJ2_MATRIXSOLUTIONFACTORY_H
