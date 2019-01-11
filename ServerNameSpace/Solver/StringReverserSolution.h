//
// Created by stav on 1/5/19.
//

#ifndef PROJ2_STRINGREVERSERSOLUTION_H
#define PROJ2_STRINGREVERSERSOLUTION_H

#include "Solution.h"
class StringReverserSolution: public Solution<string>{
private:
    string solution;
public:
    StringReverserSolution(vector<string>& sol){
        //convert string vect into one string
        for (int i = 0; i < sol.size(); ++i) {
            solution+= sol[i];
        }
    }
    string ToString(){
        return this->solution;
    }

};
#endif //PROJ2_STRINGREVERSERSOLUTION_H
