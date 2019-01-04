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
#include "../Solver/Searchable.h"
#define SEPERATOR "RESOLVED PROBLEM"
#define SOLUTION "SOLUTION"
using namespace std;
template <class Problem, class Solution>
class FileTextHendler {
private:
    string path;
public:
    FileTextHendler(string path){
        this->path= path;
    }
    /**
 * WriteResolvedProblem
 * @param prob
 * @param sol
 * write problem and solution to text file
 */
    void WriteResolvedProblem(Problem prob, Solution sol){
        std::ofstream outFile;
        outFile.open(path,std::ios_base::app);
        outFile<<SEPERATOR;
        outFile<<prob;
        outFile<<SOLUTION;
        outFile<<sol<<endl;
        outFile.close();

    }
/**
 * ReadResolvedProblem
 * @return tuple of string and solution
 */
    void ReadResolvedProblems( std::unordered_map<Searchable<Problem>, Solution> & cachedMap){
        std::ifstream inFile;
        string line;
        vector<tuple<vector<string>,vector< string>>> resolvedProblems;
        vector<string> currentPro;
        vector<string> currentSol;
        inFile.open(this->path);
        while (std::getline(inFile,line)){
            //read each ResolvedProblem
            if(line==SEPERATOR){
                std::getline(inFile,line);
                //Read untill solution
                while (line!= SOLUTION){
                    currentPro.push_back(line);
                }
                //move on above soultion seperator
                std::getline(inFile,line);
                //Read untill next problem
                while (line!= SEPERATOR){
                    currentSol.push_back(line);
                }
                shared_ptr<Searchable<Problem>> newPro= make_shared<Searchable<Problem>>(currentPro);
                //Todo: create solution object and add vector<string> constructor
                currentPro.clear();
                currentSol.clear();
            }
        }
        return resolvedProblems;

    }
};


#endif //PROJ2_FILETEXTHENDLER_H
