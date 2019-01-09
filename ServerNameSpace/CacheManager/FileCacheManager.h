//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <unordered_map>
#include <memory.h>
#include "../Utils/FileTextHendler.h"
#include "../Solver/Searchable.h"
#include "../Solver/Solution.h"

using namespace std;
#define PATH "cache.txt"
template<class P, class S>
class FileCacheManager : public CacheManager<P, S> {
 private:
  std::unordered_map<shared_ptr<Searchable<P>>, shared_ptr<Solution<S>>> cachedMap;
  shared_ptr<FileTextHendler<P, S>> fileTextHendler;
 public:
  FileCacheManager() {
      fileTextHendler = make_shared<FileTextHendler<P, S>>(PATH);
      fileTextHendler->ReadResolvedProblems(this->cachedMap);
  }
  /**
   * IsSolutionExist
   * @param problem
   * @return true if solution to specific problem is exist or false otherwise
   */
  virtual bool IsSolutionExist(shared_ptr<Searchable<P>> problem) {
      for(auto it = this->cachedMap.cbegin(); it != this->cachedMap.end(); ++it){
          if((*it).first->ToString()== problem->ToString()){
              return true;
          }
      }
      return false;

  }
  /**
   * AddSolution
   * @param pr
   * @param so
   * add new solution to chach map
   */
  void AddSolution(shared_ptr<Searchable<P>> pr, shared_ptr<Solution<S>> so) {
      if (!this->IsSolutionExist(pr)) {
          this->cachedMap[pr] = so;
          this->fileTextHendler->WriteResolvedProblem(pr, so);
      }
  }
  /**
   * GetSolution
   * @param pr
   * @return solution by its problem key at o(1) compexity
   */
  shared_ptr<Solution<S>> GetSolution(shared_ptr<Searchable<P>> pr) {
    /*  try {
          shared_ptr<Solution<S>> so = this->cachedMap.at(pr);
          return so;
      }catch (const out_of_range &e){
          return nullptr;
      }*/
      for(auto it = this->cachedMap.cbegin(); it != this->cachedMap.end(); ++it){
          if((*it).first->ToString()== pr->ToString()){
              return (*it).second;
          }
      }
  }
};
#endif //PROJ2_FILECACHEMANAGER_H
