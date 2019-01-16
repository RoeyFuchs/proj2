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
/**
 * ==
 * @param st
 * @return true if states are equal or false otherwise
 */
    bool operator ==(State st){
        return (this->state==st.GetState());
    }
    /**
     * GetCost
     * @return cost
     */
    double GetCost() {
        return this->cost;
    }
    /**
     * SetComeFrom
     * @param comeFrom
     */
    void SetComeFrom(shared_ptr<State<T>> comeFrom) {
        this->cameFrom = comeFrom;
    }
    /**
     * GetComeFrom
     * @return sharePtr of state of T
     */
  shared_ptr<State<T>> GetCameFrom() {
        if (this->cameFrom == NULL) {
            return nullptr;
        }
        return this->cameFrom;
    }
    /**
     * GetPathCost
     * @return path of cost
     */
    double GetPathCost() {
        if(cameFrom != nullptr) {
            return cameFrom->GetPathCost()+this->GetCost();
        }
        return this->GetCost();
    }
    /**
     * SetCost
     * @param cost
     */
    void SetCost(double cost) {
        this->cost = cost;
    }
/**
 * GetNumOfChildren
 * @return num of children
 */
    double GetNumOfChildren() {
        if(this->GetCameFrom() != nullptr) {
            return this->GetCameFrom()->GetNumOfChildren()+1;
        } else {
            return 0;
        }
    }
};
#endif //PROJ2_STATE_H
