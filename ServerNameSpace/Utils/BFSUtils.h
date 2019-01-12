#ifndef PROJ2_BFSUTILS_H
#define PROJ2_BFSUTILS_H
#include <memory>
#include <vector>
#include <queue>
#include <list>
#include "../Solver/State.h"
#include "Point.h"
#include "Comperators.h"



/**
 * check if value is inside a priority queue
 * @param val  the value to check
 * @param que the priority queue to check in
 * @return true or false
 */
static bool CheckIfValueInSidePriorityQueue(std::shared_ptr<State<std::shared_ptr<Point>>> val,
                                            std::priority_queue<std::shared_ptr<State<std::shared_ptr<Point>>>,
                                            std::vector<std::shared_ptr<State<std::shared_ptr<Point>>>>,
                                            CompareStep<std::shared_ptr<Point>>> que) {
    while (!que.empty()) {
        if (que.top() == val) {
            return true;
        }
        que.pop();
    }
    return false;
}
/**
 * check if there is a better path in a priority queue
 * @param val the value to check with
 * @param que the priority queue
 * @return true or false
 */
bool CheckIfPathBetterInPriorityQueue(std::shared_ptr<State<std::shared_ptr<Point>>> val,
                                      std::priority_queue<std::shared_ptr<State<std::shared_ptr<Point>>>,
                                      vector<std::shared_ptr<State<std::shared_ptr<Point>>>>,
                                      CompareStep<std::shared_ptr<Point>>> &que) {
    std::list<std::shared_ptr<State<std::shared_ptr<Point>>>> temp;
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
/**
 * check if there is a better path in a list
 * @param val the value to check with
 * @param list the list
 * @return true or false
 */
bool CheckIfPathBetterList(std::shared_ptr<State<std::shared_ptr<Point>>> val,
                           std::list<std::shared_ptr<State<std::shared_ptr<Point>>>>& list) {

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

/**
 * remove a specific value from a priority queue
 * @param val the value to remove
 * @param que the queue to remove from
 */
static void RemoveValFromPriorityQueueByValue(std::shared_ptr<State<std::shared_ptr<Point>>> val,
                                              std::priority_queue<std::shared_ptr<State<std::shared_ptr<Point>>>,
                                              vector<std::shared_ptr<State<std::shared_ptr<Point>>>>,
                                              CompareStep<std::shared_ptr<Point>>>& que) {
    std::list<std::shared_ptr<State<std::shared_ptr<Point>>>> temp;
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
/**
 * check if a value is inside a list
 * @param val the value to check
 * @param list the list
 * @return true or false
 */
static bool CheckIfValueInsideList(std::shared_ptr<State<std::shared_ptr<Point>>> val, std::list<std::shared_ptr<State<std::shared_ptr<Point>>>> list) {
    for(auto itr = list.begin(); itr != list.end(); ++itr) {
        if(itr->get()->GetState()->operator==(*val->GetState().get())) {
            return true;
        }
    }
    return false;
}

#endif //PROJ2_BFSUTILS_H
