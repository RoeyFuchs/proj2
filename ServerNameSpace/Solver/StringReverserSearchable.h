//
// Created by stav on 1/4/19.
//

#include "Searchable.h"
#include "State.h"

class StringReverserSearchable: public Searchable <string>{
private:
    string problem;
public:
    StringReverserSearchable(string problem){
        this->problem= problem;
    }
    StringReverserSearchable(vector<string> pro){
        for (int i = 0; i <problem.size() ; ++i) {
            this->problem+= pro[i];
        }
    }
    State<string> GetInitialState(){
        return this->problem;
    }
    //TODO: understand how to implement is goal for string
    bool IsGoalState(State<string> state){

    }
    vector<State<string>>GetAllPossiableStates(State<string> s){}

};