//
// Created by stav on 1/4/19.
//

#include "Searchable.h"
#include "State.h"

class StringReverserSearchable: public Searchable <string>{
private:
    string problem;
public:
    StringReverserSearchable(vector<string>& pro): Searchable(pro){
        for (int i = 0; i <pro.size() ; ++i) {
            this->problem+= pro[i];
        }
    }
    /**
     * GetInitialState
     * @return  shared ptr of initial state
     */
    shared_ptr<State<string>> GetInitialState(){
        return make_shared<State<string>>(this->problem);
    }
    /**
     * IsGoalState
     * @param state
     * @return true if its goal state or false otherwise
     */
    bool IsGoalState(shared_ptr<State<string>> state){
    return true;
    }
    /**
     * GetAllPossiableStates
     * @param s
     * @return all possiable states of string
     */
    vector<shared_ptr<State<string>>>GetAllPossiableStates(shared_ptr<State<string>> s){
        vector<shared_ptr<State<string>>> vec;
        return vec;
    }
/**
 * ToString
 * @return problem at string representation
 */
    string ToString(){
        return problem;
    }

};