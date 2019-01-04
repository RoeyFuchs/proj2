//
// Created by stav on 1/3/19.
//

#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H
#include <unordered_map>
template <class Problem, class Solution>
class CacheManager{
public:
    /**
     * IsSolutionExist
     * @param problem
     * @return true if solution to specific problem is exist or false otherwise
     */
    virtual bool IsSolutionExist(Problem problem)=0;
    /**
     * AddSolution
     * @param pr
     * @param so
     * add new solution to chach map
     */
    virtual void AddSolution(Problem pr, Solution so)=0;
    /**
     * GetSolution
     * @param pr
     * @return solution by its problem key
     */
    virtual Solution GetSolution(Problem pr)=0;
};
#endif //PROJ2_CACHEMANAGER_H
