//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_STRINGSEARCHABLEFACTORY_H
#define PROJ2_STRINGSEARCHABLEFACTORY_H
#include "SearchableFactory.h"
#include "../Solver/StringReverserSearchable.h"
class StringSearchableFactory:public SearchableFactory<string>{
 public:
  virtual shared_ptr<Searchable<string>> Create(vector<std::string> vec){
      shared_ptr<Searchable<string>> a = make_shared<StringReverserSearchable>(vec);
      return a;
  }
};
#endif //PROJ2_STRINGSEARCHABLEFACTORY_H
