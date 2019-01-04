//
// Created by stav on 1/3/19.
//

#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H
#include <unordered_map>
template <class Problem, class Solution>
class CacheManager{
private:
    std::unordered_map<Problem, Solution> cachedMap;
public:
    /**
     * IsSolutionExist
     * @param problem
     * @return true if solution to specific problem is exist or false otherwise
     */
    bool IsSolutionExist(Problem problem){
        if(cachedMap.find(problem) != cachedMap.end()){
            return true;
        }
        return false;
    }
    /**
     * AddSolution
     * @param pr
     * @param so
     * add new solution to chach map
     */
    void AddSolution(Problem pr, Solution so){
        this->cachedMap[pr]=so;
    }
    /**
     * GetSolution
     * @param pr
     * @return solution by its problem key
     */
    Solution GetSolution(Problem pr){
        return this->cachedMap[pr];
    }
};
#endif //PROJ2_CACHEMANAGER_H
