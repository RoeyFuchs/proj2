//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H
#include <memory>

template <class Problem, class Solution>
class Searcher{
public:
    virtual shared_ptr<Solution> Search(shared_ptr<Problem> problem)=0;
};
#endif //PROJ2_SEARCHER_H
