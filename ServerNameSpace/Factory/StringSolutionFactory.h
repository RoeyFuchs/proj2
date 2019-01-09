//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_STRINGSOLUTIONFACTORY_H
#define PROJ2_STRINGSOLUTIONFACTORY_H
#include "SolutionFactory.h"
class StringSolutionFactory: public SolutionFactory<string>{
  virtual shared_ptr<Solution<string>> Create(vector<std::string> vec){
      return make_shared<SolutionFactory>(vec);
  }
};
#endif //PROJ2_STRINGSOLUTIONFACTORY_H
