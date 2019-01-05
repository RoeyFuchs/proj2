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
class Searchable{
public:
    Searchable(vector<string> &vec){}
    virtual string ToString()=0;

    virtual State<T> GetInitialState()=0;
    virtual bool IsGoalState(State<T> state)=0;
    virtual vector<State<T>>GetAllPossiableStates(State<T> s)=0;
};
#endif //PROJ2_SEARCHABLE_H
