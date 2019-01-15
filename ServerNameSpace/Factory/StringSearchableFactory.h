//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_STRINGSEARCHABLEFACTORY_H
#define PROJ2_STRINGSEARCHABLEFACTORY_H
#include "SearchableFactory.h"
#include "../Solver/StringReverserSearchable.h"
class StringSearchableFactory:public SearchableFactory<StringReverserSearchable>{
 public:
  /**
   * Create
   * @param vec
   * @return shared pointer to searchable
   */
  virtual shared_ptr<StringReverserSearchable> Create(vector<std::string> vec){
      shared_ptr<StringReverserSearchable> a = make_shared<StringReverserSearchable>(vec);
      return a;
  }
};
#endif //PROJ2_STRINGSEARCHABLEFACTORY_H
