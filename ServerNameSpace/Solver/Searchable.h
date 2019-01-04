//
// Created by stav on 1/3/19.
//

#ifndef PROJ2_SEARCHABLE_H
#define PROJ2_SEARCHABLE_H

#include <string>
#include <vector>
#include "State.h"
using namespace std;
template <class T>
class Searchable<T>{
public:
    virtual State<T> GetInitialState()=0;
    virtual State<T> GetGoalState()=0;
    virtual vector<State<T>>GetAllPossiableStates(State<T> s);
};
#endif //PROJ2_SEARCHABLE_H
