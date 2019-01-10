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
    shared_ptr<State<string>> GetInitialState(){
        return make_shared<State<string>>(this->problem);
    }
    //TODO: understand how to implement is goal for string
    bool IsGoalState(shared_ptr<State<string>> state){
    return true;
    }
    vector<shared_ptr<State<string>>>GetAllPossiableStates(shared_ptr<State<string>> s){
        vector<shared_ptr<State<string>>> vec;
        return vec;
    }

    string ToString(){
        return problem;
    }

};