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
  /**
   * Create
   * @param vec
   * @return shared pointer ro problem
   */
    virtual shared_ptr<P> Create(vector<std::string> vec)=0;
};
#endif //PROJ2_FACTORY_H
