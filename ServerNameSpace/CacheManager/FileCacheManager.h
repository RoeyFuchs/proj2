//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "../Utils/FileTextHendler.h"

using namespace std;
#define PATH "cache.txt"
template<class P, class S>
class FileCacheManager : public CacheManager<P, S> {
 private:
  std::unordered_map<string, shared_ptr<S>> cachedMap;
  shared_ptr<FileTextHendler<P, S>> fileTextHendler;
 public:
  FileCacheManager(string& searchableFactoryName,shared_ptr<SearchableFactory<P>> searchableFactory,
                   string& solutionFactoryName, shared_ptr<SolutionFactory<S>> solutionFactory) {
      fileTextHendler = make_shared<FileTextHendler<P, S>>(PATH,searchableFactoryName,
          searchableFactory,solutionFactoryName,solutionFactory);
      std::unordered_map<shared_ptr<P>, shared_ptr<S>> cachedMap1 =
          fileTextHendler->ReadResolvedProblems();
          for (auto it = cachedMap1.cbegin(); it != cachedMap1.end(); ++it) {
              this->cachedMap[(*it).first->ToString()] = (*it).second;
          }
  }
  /**
   * IsSolutionExist
   * @param problem
   * @return true if solution to specific problem is exist or false otherwise
   */
  virtual bool IsSolutionExist(shared_ptr<P> problem) {
      int result= (this->cachedMap.count(problem->ToString()));
      return result;

  }
  /**
   * AddSolution
   * @param pr
   * @param so
   * add new solution to chach map
   */
  void AddSolution(shared_ptr<P> pr, shared_ptr<S> so) {
      if (!this->IsSolutionExist(pr)) {
          this->cachedMap[(*pr).ToString()] = so;
          this->fileTextHendler->WriteResolvedProblem(pr ,so);
      }
  }
  /**
   * GetSolution
   * @param pr
   * @return solution by its problem key at o(1) compexity
   */
  shared_ptr<S> GetSolution(shared_ptr<P> pr) {
      try {
          shared_ptr<S> so = this->cachedMap[pr->ToString()];
          return so;
      }catch (const out_of_range &e){
          return nullptr;
      }
  }
};
#endif //PROJ2_FILECACHEMANAGER_H
