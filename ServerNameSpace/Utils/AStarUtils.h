
#ifndef PROJ2_ASTARUTILS_H
#define PROJ2_ASTARUTILS_H
#include <memory>
#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include "Comperators.h"
#include "Point.h"
#include "../Solver/State.h"
double GetHValue(shared_ptr<State<shared_ptr<Point>>> state, shared_ptr<State<shared_ptr<Point>>> endPoint) {
    double xVal = state->GetState()->getX() - endPoint->GetState()->getX();
    xVal = pow(xVal, 2);
    double yVal = state->GetState()->getY() - endPoint->GetState()->getY();
    yVal = pow(yVal, 2);
    double sum = xVal+yVal;
    sum = sqrt(sum);
    return sum;
}
double GetGValue(shared_ptr<State<shared_ptr<Point>>> state) {
    return state->GetPathCost();
}
double GetFValue(shared_ptr<State<shared_ptr<Point>>> state, shared_ptr<State<shared_ptr<Point>>> endPoint) {
    return GetHValue(state, endPoint) + GetGValue(state);
}

template<typename T>
class CompareStepAStar {
  shared_ptr<State<shared_ptr<Point>>> endPoint;
 public:
  CompareStepAStar(shared_ptr<State<shared_ptr<Point>>> endPoint) {
      this->endPoint = endPoint;
  }
  bool operator()(shared_ptr<State<T>> & s1, shared_ptr<State<T>> & s2) {
      // return "true" if "p1" is ordered before "p2", for example:
      return GetFValue(s1, this->endPoint) > GetFValue(s2, this->endPoint);
  }


};
bool CheckIfCostBetterInPriorityQueueAStar(std::shared_ptr<State<std::shared_ptr<Point>>> val,
                                      std::priority_queue<std::shared_ptr<State<std::shared_ptr<Point>>>,
                                      vector<std::shared_ptr<State<std::shared_ptr<Point>>>>,
                                                          CompareStepAStar<shared_ptr<Point>>> &que) {
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
 * remove a specific value from a priority queue
 * @param val the value to remove
 * @param que the queue to remove from
 */
static void RemoveValFromPriorityQueueByValueAStar(std::shared_ptr<State<std::shared_ptr<Point>>> val,
                                              std::priority_queue<std::shared_ptr<State<std::shared_ptr<Point>>>,
                                                                  vector<std::shared_ptr<State<std::shared_ptr<Point>>>>,
                                                                  CompareStepAStar<std::shared_ptr<Point>>>& que) {
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
static bool CheckIfValueInsideListAStar(std::shared_ptr<State<std::shared_ptr<Point>>> val, std::list<std::shared_ptr<State<std::shared_ptr<Point>>>> list) {
    for(auto itr = list.begin(); itr != list.end(); ++itr) {
        if(itr->get()->GetState()->operator==(*val->GetState().get())) {
            return true;
        }
    }
    return false;
}




static bool CheckIfValueInSidePriorityQueueAStar(std::shared_ptr<State<std::shared_ptr<Point>>> val,
                                                 std::priority_queue<std::shared_ptr<State<std::shared_ptr<Point>>>,
                                                                     std::vector<std::shared_ptr<State<std::shared_ptr<Point>>>>,
                                                                     CompareStepAStar<std::shared_ptr<Point>>> que) {
    while (!que.empty()) {
        if (que.top()->GetState().get()->operator==(*val->GetState().get())) {
            return true;
        }
        que.pop();
    }
    return false;
}

#endif //PROJ2_ASTARUTILS_H
