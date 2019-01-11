
#ifndef PROJ2_UTILS_H
#define PROJ2_UTILS_H
#define DELIMITER ","

#include <queue>
#include <list>
#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include "../Utils/Point.h"
#include "../Utils/Comperators.h"



/**
 * convert a vector of strings to vector of vectors of ints (Matrix)
 * @param vec the vector
 * @return vector of vectors of ints
 */
static std::vector<std::vector<int>> ConvertStringToMatrix(std::vector<std::string> vec) {

    std::vector<std::vector<int>> matrix;

    for (int i = 0; i < vec.size(); ++i) {
        std::string s = vec.at(i);
        std::string delimiter = DELIMITER;
        std::vector<int> row;

        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            row.push_back(stoi(token));
            s.erase(0, pos + delimiter.length());
        }
        row.push_back(stoi(s));
        matrix.push_back(row);
    }
    return matrix;
}
/**
 * slice a vector
 * @tparam T type of vector
 * @param myVec the vector
 * @param beginIndex start index
 * @param endIndex end index
 * @return the sub vector
 */
template<class T>
std::vector<T> Slice(std::vector<T> myVec, int beginIndex, int endIndex) {
    std::vector<T> newVec;
    for (int i = beginIndex; i <= endIndex; ++i) {
        newVec.push_back(myVec[i]);
    }
    return newVec;

}
/**
 * SliceInitialNumbers
 * @param name
 * @return  remove initial numbers from string if exist
 */
static std::string SliceInitialNumbers(std::string name){
    int i=0;
    //remove initial numbers from string
    while (i<name.length() && !((name[i]>='A'&&name[i]<='Z')||(name[i]>='a'&&name[i]<='z'))){
        name.erase(0,1);
    }
    return name;
}

#endif //PROJ2_UTILS_H
