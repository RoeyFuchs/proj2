//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_SOLUTIONFACTORY_H
#define PROJ2_SOLUTIONFACTORY_H
#include <memory>
#include <vector>
#include "../Solver/Solution.h"
template <class S>
class SolutionFactory{
 public:
  /**
   * Create
   * @param vec
   * @return pointer to solution of prolem
   */
   virtual shared_ptr<S> Create(vector<std::string> vec)=0;
};
#endif //PROJ2_SOLUTIONFACTORY_H
