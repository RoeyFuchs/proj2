//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_MATRIXSEARCHABLEFACTORY_H
#define PROJ2_MATRIXSEARCHABLEFACTORY_H
#include "SearchableFactory.h"
#include "../Solver/MatrixSearchable.h"
class MatrixSearchableFactory:public SearchableFactory<shared_ptr<Point>>{
  virtual shared_ptr<Searchable<shared_ptr<Point>>> Create(vector<std::string> vec){
      return make_shared<MatrixSearchableFactory>(vec);
  }

};
#endif //PROJ2_MATRIXSEARCHABLEFACTORY_H
