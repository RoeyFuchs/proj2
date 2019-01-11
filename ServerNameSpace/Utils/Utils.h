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
#include "../Utils/Point.h"
#include "../Utils/Comperators.h"


static bool CheckIfValueInSidePriorityQueue(shared_ptr<State<shared_ptr<Point>>> val,
                                            std::priority_queue<shared_ptr<State<shared_ptr<Point>>>,
                                                                vector<shared_ptr<State<shared_ptr<Point>>>>,
                                                                CompareStep<shared_ptr<Point>>> que) {
    while (!que.empty()) {
        if (que.top() == val) {
            return true;
        }
        que.pop();
    }
    return false;
}

bool CheckIfPathBetterInPriorityQueue(shared_ptr<State<shared_ptr<Point>>> val,
                                      std::priority_queue<shared_ptr<State<shared_ptr<Point>>>,
                                                          vector<shared_ptr<State<shared_ptr<Point>>>>,
                                                          CompareStep<shared_ptr<Point>>> &que) {
    std::list<shared_ptr<State<shared_ptr<Point>>>> temp;
    bool better = false;
    while(!que.empty()) {
        if(que.top()->GetState()->operator==(*val->GetState().get())) {
            if(val->GetPathCost() < que.top()->GetPathCost()){
                better = true;
            } else {
                better = false;
            }
        }
        temp.push_back(que.top());
        que.pop();
    }
    for(auto value : temp) {
        que.push(value);
    }
    return better;

}
bool CheckIfPathBetterList(shared_ptr<State<shared_ptr<Point>>> val,
                       std::list<shared_ptr<State<shared_ptr<Point>>>>& list) {

    bool better = false;
    for(auto value : list) {
        if(value->GetState()->operator==(*val->GetState().get())) {
            if(val->GetPathCost() < value->GetPathCost()) {
                better = true;
            }
        }
    }
    return better;

}

static void RemoveValFromPriorityQueue(shared_ptr<State<shared_ptr<Point>>> val,
                                            std::priority_queue<shared_ptr<State<shared_ptr<Point>>>,
                                                                vector<shared_ptr<State<shared_ptr<Point>>>>,
                                                                CompareStep<shared_ptr<Point>>>& que) {
    std::list<shared_ptr<State<shared_ptr<Point>>>> temp;
    while(!que.empty()) {
        if(que.top() == val) {
            que.pop();
            break;
        }
        temp.push_back(que.top());
        que.pop();
    }
    for(auto& value : temp) {
        que.push(value);
    }
}

static void RemoveValFromPriorityQueueByValue(shared_ptr<State<shared_ptr<Point>>> val,
                                       std::priority_queue<shared_ptr<State<shared_ptr<Point>>>,
                                                           vector<shared_ptr<State<shared_ptr<Point>>>>,
                                                           CompareStep<shared_ptr<Point>>>& que) {
    std::list<shared_ptr<State<shared_ptr<Point>>>> temp;
    while(!que.empty()) {
        if(que.top()->GetState()->operator==(*val->GetState().get())) {
            que.pop();
            break;
        }
        temp.push_back(que.top());
        que.pop();
    }
    for(auto& value : temp) {
        que.push(value);
    }
}
static bool CheckIfValueInsideList(shared_ptr<State<shared_ptr<Point>>> val, std::list<shared_ptr<State<shared_ptr<Point>>>> list) {
    for(auto itr = list.begin(); itr != list.end(); ++itr) {
        if(itr->get()->GetState()->operator==(*val->GetState().get())) {
            return true;
        }
    }
    return false;
}



static std::vector<std::vector<int>> ConvertStringToMatrix(std::vector<std::string> vec) {

    std::vector<std::vector<int>> matrix;

    for (int i = 0; i < vec.size(); ++i) {
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
