

#ifndef PROJ2_ASTAR_H
#define PROJ2_ASTAR_H

#include "State.h"
#include "MatrixSearchable.h"
#include "Searcher.h"
#include "MatrixSolution.h"
#include "../Utils/AStarUtils.h"
class AStar : public Searcher<MatrixSearchable, MatrixSolution> {
  shared_ptr<State<shared_ptr<Point>>> solution;
  int visited;

 public:
  AStar() = default;
/**
 * Search
 * @param problem
 * @return Matrix solution to a problem bu a star algorythm
 */
  shared_ptr<MatrixSolution> Search(shared_ptr<MatrixSearchable> problem) {
      this->solution = nullptr;
      this->visited = 0;
      std::priority_queue<shared_ptr<State<shared_ptr<Point>>>,
                          vector<shared_ptr<State<shared_ptr<Point>>>>,
                          CompareStepAStar<shared_ptr<Point>>> open {CompareStepAStar<shared_ptr<Point>>(problem->GetEndPoint())};
      open.push(problem->GetInitialState());
      std::list<shared_ptr<State<shared_ptr<Point>>>> closed;

      while(!open.empty()) {
          this->visited++;
          shared_ptr<State<shared_ptr<Point>>> current = open.top();
          if(problem->IsGoalState(current)) {
              this->solution = current;
              break;
          }
          open.pop();
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = problem->GetAllPossiableStates(current);
          //move on all its suceessors
          for(auto children : successor) {
              children->SetComeFrom(current);
              double fVal = GetFValue(children, problem->GetEndPoint());
              if(CheckIfValueInsideListAStar(children, closed)) {
                  continue;
              }
              if(CheckIfValueInSidePriorityQueueAStar(children, open)) {
                  if(CheckIfCostBetterInPriorityQueueAStar(children, open)) {
                      RemoveValFromPriorityQueueByValueAStar(children, open);
                  } else {
                      continue;
                  }
              }
              open.push(children);
          }
          closed.push_back(current);
      }
      shared_ptr<MatrixSolution> sol=make_shared<MatrixSolution> (this->solution);
      return sol;
  }
};

#endif //PROJ2_ASTAR_H
