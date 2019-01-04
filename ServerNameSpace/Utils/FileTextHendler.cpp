//
// Created by stav on 1/4/19.
//
/*
#include <fstream>
#include "FileTextHendler.h"
#define SEPERATOR "RESOLVED PROBLEM"
#define SOLUTION "SOLUTION:"
/**
 * WriteResolvedProblem
 * @param prob
 * @param sol
 * write problem and solution to text file
 */
/*
void FileTextHendler::WriteResolvedProblem(Problem prob, Solution sol) {
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
/*
vector<tuple<vector<string>,vector< string>>> FileTextHendler::ReadResolvedProblems() {
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
            resolvedProblems.push_back(tuple<currentPro, currentSol);
            currentPro.clear();
            currentSol.clear();
        }
    }
    return resolvedProblems;
}
*/