//
// Created by roey on 1/5/19.
//

#ifndef PROJ2_UTILS_H
#define PROJ2_UTILS_H

#include <queue>
#include <list>
#include <vector>
#include <string>
#include <regex>
#include <iostream>

template<typename T>
static bool CheckIfValueInSidePriorityQueue(T val, std::priority_queue<T> que) {
    while (!que.empty()) {
        if (que.top() == val) {
            return true;
        }
        que.pop();
    }
    return false;
}

static std::vector<std::vector<int>> ConvertStringToMatrix(std::vector<std::string> vec) {


    std::vector<std::vector<int>> matrix;

    for(int i = 0; i < vec.size(); ++i) {
        std::string s = vec.at(i);
        std::string delimiter = ",";
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

template <class T>
std::vector<T> Slice(std::vector<T> myVec, int beginIndex, int endIndex) {
    std::vector<T> newVec;
    for (int i = beginIndex; i <= endIndex; ++i) {
        newVec.push_back(myVec[i]);
    }
    return newVec;

}

#endif //PROJ2_UTILS_H
