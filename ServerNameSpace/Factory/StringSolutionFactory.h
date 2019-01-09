//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_STRINGSOLUTIONFACTORY_H
#define PROJ2_STRINGSOLUTIONFACTORY_H
#include "../Solver/StringReverserSolution.h"
#include "SolutionFactory.h"
class StringSolutionFactory: public SolutionFactory<string>{
 public:
  virtual shared_ptr<Solution<string>> Create(vector<std::string> vec){
      return make_shared<StringReverserSolution>(vec);
  }
};
#endif //PROJ2_STRINGSOLUTIONFACTORY_H
