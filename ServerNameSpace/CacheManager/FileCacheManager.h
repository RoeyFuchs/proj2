//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <unordered_map>
#include "../Utils/FileTextHendler.h"

#define PATH "cache.txt"
template <class Problem, class Solution>
class FileCacheManager: public CacheManager<Problem,Solution> {
private:
    std::unordered_map<Problem, Solution> cachedMap;
public:
    FileCacheManager(){
        //TODO: add convertor between problem\sol to string
        FileTextHendler fileTextHendler(PATH);
        fileTextHendler.ReadResolvedProblems();
    }
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


#endif //PROJ2_FILECACHEMANAGER_H
