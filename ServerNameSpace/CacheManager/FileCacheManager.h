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

#define PATH "cache.txt"
template <class P,class S>
class FileCacheManager: public CacheManager<P,S> {
private:
    std::unordered_map<shared_ptr<Searchable<P>>,shared_ptr<Solution<S>>> cachedMap;
    shared_ptr<FileTextHendler<P, S>> fileTextHendler;
public:
    FileCacheManager(){
        fileTextHendler= make_shared<FileTextHendler<P, S>>(PATH);
        fileTextHendler->ReadResolvedProblems(this->cachedMap);
    }
    /**
     * IsSolutionExist
     * @param problem
     * @return true if solution to specific problem is exist or false otherwise
     */
    bool IsSolutionExist(shared_ptr<Searchable<P>> problem){
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
    void AddSolution(shared_ptr<Searchable<P>> pr, shared_ptr<Solution<S>> so){
        this->cachedMap[pr]=so;
        this->fileTextHendler->WriteResolvedProblem(pr,so);
    }
    /**
     * GetSolution
     * @param pr
     * @return solution by its problem key
     */
    shared_ptr<Solution<S>> GetSolution(shared_ptr<Searchable<P>> pr){
        return this->cachedMap[pr];
    }
};


#endif //PROJ2_FILECACHEMANAGER_H
