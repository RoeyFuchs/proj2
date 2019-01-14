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
    void WriteResolvedProblem(shared_ptr<Searchable<P>> prob,shared_ptr<Solution<S>> sol){
        std::ofstream outFile;
        outFile.open(path,std::ios_base::app);
        outFile<<SEPERATOR<<endl;
        outFile<<SliceInitialNumbers( typeid((*prob)).name())<<endl;
        outFile<<prob->ToString();
        outFile<<SOLUTION<<endl;
        outFile<<SliceInitialNumbers( typeid((*sol)).name())<<endl;
        outFile<<sol->ToString();
        outFile.close();

    }
/**
 * ReadResolvedProblem
 * @return tuple of string and solution
 */
  std::unordered_map<shared_ptr<Searchable<P>>,shared_ptr<Solution<S>>>
      ReadResolvedProblems( ){
        std::ifstream inFile;
      std::unordered_map<shared_ptr<Searchable<P>>,shared_ptr<Solution<S>>>cachedMap;
        string line;
        vector<string> currentPro;
        vector<string> currentSol;
        inFile.open(this->path);
      std::getline(inFile,line);
        while (line.size()>0){
            //read each ResolvedProblem
            if(line==SEPERATOR){
                std::getline(inFile,line);
                string searchableType= line;
                std::getline(inFile,line);
                //Read untill solution
                while (line.size()>0 &&line!= SOLUTION){
                    currentPro.push_back(line);
                    std::getline(inFile,line);
                }
                //move on above soultion seperator
                std::getline(inFile,line);
                string solutionType= line;
                std::getline(inFile,line);
                //Read untill next problem
                while (line.size()>0 && line!= SEPERATOR){
                    currentSol.push_back(line);
                    std::getline(inFile,line);
                }
                shared_ptr<Searchable<P>> newPro= this->searchableFactory[searchableType]->Create(currentPro);
                shared_ptr<Solution<S>> newSol= this->solutionFactory[solutionType]->Create(currentSol);

                cachedMap[newPro]= newSol;
                currentPro.clear();
                currentSol.clear();
            }
        }
      return cachedMap;
    }
};


#endif //PROJ2_FILETEXTHENDLER_H
