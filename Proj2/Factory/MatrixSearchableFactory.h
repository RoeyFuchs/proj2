//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_MATRIXSEARCHABLEFACTORY_H
#define PROJ2_MATRIXSEARCHABLEFACTORY_H
#include "SearchableFactory.h"
#include "../Solver/MatrixSearchable.h"
class MatrixSearchableFactory:public SearchableFactory<MatrixSearchable>{
 public:
  /**
   * Create
   * @param vec
   * @return pointer to searchable
   */
  virtual shared_ptr<MatrixSearchable> Create(vector<std::string> vec){
    shared_ptr<MatrixSearchable> a= make_shared<MatrixSearchable>(vec);
    return a;
  }

};
#endif //PROJ2_MATRIXSEARCHABLEFACTORY_H
