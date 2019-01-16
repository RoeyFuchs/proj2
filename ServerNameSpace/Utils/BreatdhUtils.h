#ifndef PROJ2_BREATDHUTILS_H
#define PROJ2_BREATDHUTILS_H
#include <memory>
#include <queue>
#include "Point.h"
#include "../Solver/State.h"
static bool CheckIfValueInSidePriorityQueue(std::shared_ptr<State<std::shared_ptr<Point>>> val,
                                            std::queue<std::shared_ptr<State<std::shared_ptr<Point>>>> que) {
    while (!que.empty()) {
        if (que.front()->GetState()->operator==(*val->GetState().get())) {
            return true;
        }
        que.pop();
    }
    return false;
}

#endif //PROJ2_BREATDHUTILS_H
