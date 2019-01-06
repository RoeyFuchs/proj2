//
// Created by roey on 1/5/19.
//

#ifndef PROJ2_UTILS_H
#define PROJ2_UTILS_H

#include <queue>
#include <list>
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

#endif //PROJ2_UTILS_H
