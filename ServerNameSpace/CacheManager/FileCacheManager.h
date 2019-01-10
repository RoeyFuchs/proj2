//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "../Utils/FileTextHendler.h"
#include "../Utils/SharedPtrHash.h"

using namespace std;
#define PATH "cache.txt"
template<class P, class S>
class FileCacheManager : public CacheManager<P, S> {
 private:
  std::unordered_map<shared_ptr<Searchable<P>>, shared_ptr<Solution<S>>, SharedPtrSearchableHash<P>,
                     SharePtrSearchableEqualValues<P>> cachedMap2;
  //ToDo: i cant create unorderd map of searchable
  std::unordered_map<Searchable<P>, Solution<S>> cachedMap3;
  shared_ptr<FileTextHendler<P, S>> fileTextHendler;
 public:
  FileCacheManager() {
      fileTextHendler = make_shared<FileTextHendler<P, S>>(PATH);
      std::unordered_map<shared_ptr<Searchable<P>>, shared_ptr<Solution<S>>> cachedMap =
          fileTextHendler->ReadResolvedProblems();
          for (auto it = cachedMap.cbegin(); it != cachedMap.end(); ++it) {
              this->cachedMap2[(*it).first] = (*it).second;
          }
  }
  /**
   * IsSolutionExist
   * @param problem
   * @return true if solution to specific problem is exist or false otherwise
   */
  virtual bool IsSolutionExist(shared_ptr<Searchable<P>> problem) {
      for (auto it = this->cachedMap2.cbegin(); it != this->cachedMap2.end(); ++it) {
          if ((*it).first == problem) {
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
          this->cachedMap2[pr] = so;
          this->fileTextHendler->WriteResolvedProblem(pr, so);
      }
  }
  /**
   * GetSolution
   * @param pr
   * @return solution by its problem key at o(1) compexity
   */
  shared_ptr<Solution<S>> GetSolution(shared_ptr<Searchable<P>> pr) {
      /*try {
          shared_ptr<Solution<S>> so = this->cachedMap2[(*pr)];
          return so;
      }catch (const out_of_range &e){
          return nullptr;
      }*/

      for (auto it = this->cachedMap2.cbegin(); it != this->cachedMap2.end(); ++it) {
          if ((*it).first->ToString() == pr->ToString()) {
              return (*it).second;
          }
      }
  }
};
#endif //PROJ2_FILECACHEMANAGER_H
