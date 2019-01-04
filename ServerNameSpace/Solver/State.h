//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H
using namespace std;
#include <string>
template <class T>
class State{
private:
    T state;
    double cost;
    //TODO: CAME FROM
//    State<T> cameFrom;
public:
    State(T state){
        this->state= state;
    }
    string GetState(){
        return this->state;
    }

    bool operator ==(State st){
        return (this->state==st.GetState());
    }
};
#endif //PROJ2_STATE_H
