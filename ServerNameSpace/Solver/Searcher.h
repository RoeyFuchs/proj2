//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Searchable.h"
template <class Solution, class Problem>
class Searcher{
public:
    virtual Solution Search(Searchable<Problem>  problem)=0;
};
#endif //PROJ2_SEARCHER_H
