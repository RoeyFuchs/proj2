//
// Created by roey on 1/5/19.
//

#ifndef PROJ2_COMPERATORS_H
#define PROJ2_COMPERATORS_H

#include "../Solver/State.h"
template<typename T>
struct CompareStep {
  bool operator()(State<T> const & s1, State<T> const & s2) {
      // return "true" if "p1" is ordered before "p2", for example:
      return s1.GetPathCost() < s2.GetPathCost();
  }
};

#endif //PROJ2_COMPERATORS_H
