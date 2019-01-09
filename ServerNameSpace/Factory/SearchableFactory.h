#include <bits/shared_ptr.h>//
// Created by stav on 1/9/19.
//

#ifndef PROJ2_FACTORY_H
#define PROJ2_FACTORY_H
#include "../Solver/Searchable.h"
#include <memory>
#include <vector>
template <class P>
class SearchableFactory{
 public:
    virtual shared_ptr<Searchable<P>> Create(vector<std::string> vec)=0;
};
#endif //PROJ2_FACTORY_H
