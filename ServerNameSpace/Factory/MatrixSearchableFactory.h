//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_MATRIXSEARCHABLEFACTORY_H
#define PROJ2_MATRIXSEARCHABLEFACTORY_H
#include "SearchableFactory.h"
#include "../Solver/MatrixSearchable.h"
class MatrixSearchableFactory:public SearchableFactory<shared_ptr<Point>>{
 public:
  virtual shared_ptr<Searchable<shared_ptr<Point>>> Create(vector<std::string> vec){
    shared_ptr<Searchable<shared_ptr<Point>>> a= make_shared<MatrixSearchable>(vec);
    return a;
  }

};
#endif //PROJ2_MATRIXSEARCHABLEFACTORY_H
