//
// Created by stav on 1/14/19.
//

#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H
#include "../CacheManager/CacheManager.h"
#include "Searcher.h"
#include <memory.h>
template <class P, class S>
class Solver{
  shared_ptr<CacheManager<P,S>> cache;
  shared_ptr<Searcher<P,S>> searcher;
 public:
  Solver(shared_ptr<CacheManager<P,S>> cache,shared_ptr<Searcher<P,S>> searcher){
      this->cache= cache;
      this->searcher= searcher;
  }
  /**
   * Solve
   * @param problem
   * @return  solution to a problem
   */
  shared_ptr<Solution<S>> Solve(shared_ptr<Searchable<P>> problem){
      if(this->cache->IsSolutionExist(problem)){
          return this->cache->GetSolution(problem);
      }else{
          //solve the problem
          return this->searcher->Search(problem);
      }
  }
};
#endif //PROJ2_SOLVER_H
