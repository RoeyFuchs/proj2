//
// Created by stav on 1/4/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include <memory>
#include "Searchable.h"
template <class Problem, class Solution>
class Searcher{
public:
    virtual Solution Search(Problem problem)=0;
};
#endif //PROJ2_SEARCHER_H
