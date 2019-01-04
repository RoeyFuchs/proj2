//
// Created by stav on 1/4/19.
//

#include "Searchable.h"
class ReverseStringSearchable: public Searchable <string>{
private:
    string problem;
public:
    ReverseStringSearchable(string problem){
        this->problem= problem;
    }
    string GetInitialState(){
        return this->problem;
    }

};