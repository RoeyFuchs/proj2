

#ifndef PROJ2_ASTAR_H
#define PROJ2_ASTAR_H

#include "State.h"
#include "MatrixSearchable.h"
#include "Searcher.h"
#include "../Utils/BFSUtils.h"
class AStar : public Searcher<MatrixSearchable, string> {
  shared_ptr<State<shared_ptr<Point>>> initialState;
  shared_ptr<State<shared_ptr<Point>>> endState;
  MatrixSearchable *matrix;
  shared_ptr<State<shared_ptr<Point>>> solution;

 public:
  AStar(MatrixSearchable* searchble) {
      this->matrix = searchble;
  }
  string Search(MatrixSearchable problem) {
      this->matrix = &problem;
      std::priority_queue<shared_ptr<State<shared_ptr<Point>>>,
                          vector<shared_ptr<State<shared_ptr<Point>>>>,
                          CompareStep<shared_ptr<Point>>> open;
      open.push(problem.GetInitialState());
      std::list<shared_ptr<State<shared_ptr<Point>>>> closed;

      while(!open.empty()) {
          shared_ptr<State<shared_ptr<Point>>> m = open.top();
          if(problem.IsGoalState(m)) {
              //DONE
          }
          open.pop();
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = matrix->GetAllPossiableStates(m);
          for(auto n : successor) {
              if(CheckIfValueInsideList(n, closed)) {
                  continue;
              }
              double cost = m->GetPathCost() + n->GetCost();
              if (CheckIfValueInSidePriorityQueue(n, open) && cost < )

          }
      }
  }

};

#endif //PROJ2_ASTAR_H
