//
// Created by stav on 1/3/19.
//

#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H
#include <unordered_map>
#include <string>
#include <vector>
#include <memory.h>
#include <fstream>
#include <memory>
#include "../Solver/Searchable.h"
#include "../Solver/Solution.h"
template <class P, class S>
class CacheManager{
public:
    /**
     * IsSolutionExist
     * @param problem
     * @return true if solution to specific problem is exist or false otherwise
     */
    virtual bool IsSolutionExist(shared_ptr<Searchable<P>> problem)=0;
    /**
     * AddSolution
     * @param pr
     * @param so
     * add new solution to chach map
     */
    virtual void AddSolution(shared_ptr<Searchable<P>> pr, shared_ptr<Solution<S>> so)=0;
    /**
     * GetSolution
     * @param pr
     * @return solution by its problem key
     */
    virtual shared_ptr<Solution<S>> GetSolution(shared_ptr<Searchable<P>> pr)=0;
};
#endif //PROJ2_CACHEMANAGER_H
