//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_FILETEXTHENDLER_H
#define PROJ2_FILETEXTHENDLER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory.h>
#include <fstream>
#include <memory>
#include "Utils.h"
#include "../Solver/Solution.h"
#include "../Factory/MatrixSearchableFactory.h"
#include "../Factory/MatrixSolutionFactory.h"
#define SEPERATOR "$SEARCHABLE"
#define SOLUTION "$SOLUTION"
using namespace std;
template <class P, class S>
class FileTextHendler {
private:
    string path;
    unordered_map<string,shared_ptr<SearchableFactory<P>>> searchableFactory;
    unordered_map<string,shared_ptr<SolutionFactory<S>>> solutionFactory;
public:
    FileTextHendler(string path,string &searchableFactoryName,shared_ptr<SearchableFactory<P>> searchableFactory,
                   string& solutionFactoryName, shared_ptr<SolutionFactory<S>> solutionFactory){
        this->path= path;
        //initlize  factories maps
        this->searchableFactory[SliceInitialNumbers(searchableFactoryName)]
        =searchableFactory;
        this->solutionFactory[SliceInitialNumbers(solutionFactoryName)]=
           solutionFactory;
    }
    /**
 * WriteResolvedProblem
 * @param prob
 * @param sol
 * write problem and solution to text file
 */
    void WriteResolvedProblem(shared_ptr<P> prob,shared_ptr<S> sol){
        std::ofstream outFile;
        outFile.open(path,std::ios_base::app);
        outFile<<SEPERATOR<<endl;
        outFile<<SliceInitialNumbers( typeid((*prob)).name())<<endl;
        outFile<<prob->ToString();
        outFile<<SOLUTION<<endl;
        outFile<<SliceInitialNumbers( typeid((*sol)).name())<<endl;
        outFile<<sol->ToString()<<endl;
        outFile.close();

    }
/**
 * ReadResolvedProblem
 * @return tuple of string and solution
 */
  std::unordered_map<shared_ptr<P>,shared_ptr<S>>
      ReadResolvedProblems( ){
        std::ifstream inFile;
      std::unordered_map<shared_ptr<P>,shared_ptr<S>>cachedMap;
        string line;
        vector<string> currentPro;
        vector<string> currentSol;
        inFile.open(this->path);
        while (std::getline(inFile,line)){
            //read each ResolvedProblem
            if(line==SEPERATOR) {
                std::getline(inFile, line);
            }
                string searchableType= line;
                //Read untill solution
                while (std::getline(inFile,line)&&line!= SOLUTION){
                    currentPro.push_back(line);
                }
                //move on above soultion seperator
                std::getline(inFile,line);
                string solutionType= line;
                //Read untill next problem
                while (std::getline(inFile,line)&& line!= SEPERATOR){
                    currentSol.push_back(line);
                }
                shared_ptr<P> newPro= this->searchableFactory[searchableType]->Create(currentPro);
                shared_ptr<S> newSol= this->solutionFactory[solutionType]->Create(currentSol);

                cachedMap[newPro]= newSol;
                currentPro.clear();
                currentSol.clear();
        }
      return cachedMap;
    }
};


#endif //PROJ2_FILETEXTHENDLER_H
