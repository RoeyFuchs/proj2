//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H
using namespace std;

#include <memory>
#include <string>
template <class T>
class State{
private:
    T state;
    double cost;
    shared_ptr<State<T>> cameFrom;
public:
    State(T state){
        this->state= state;
    }
    T GetState(){
        return this->state;
    }

    bool operator ==(State st){
        return (this->state==st.GetState());
    }
    double GetCost() {
        return this->cost;
    }
    void SetComeFrom(shared_ptr<State<T>> comeFrom) {
        this->cameFrom = comeFrom;
    }
  shared_ptr<State<T>> GetCameFrom() {
        if (this->cameFrom == NULL) {
            return nullptr;
        }
        return this->cameFrom;
    }
    double GetPathCost() {
        if(cameFrom != nullptr) {
            return cameFrom->GetPathCost()+this->GetCost();
        }
        return this->GetCost();
    }
};
#endif //PROJ2_STATE_H
