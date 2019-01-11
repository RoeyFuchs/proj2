
#ifndef PROJ2_BFS_H
#define PROJ2_BFS_H

#include <queue>
#include <list>
#include <algorithm>
#include "Searcher.h"
#include "Solution.h"
#include "MatrixSearchable.h"
#include "MatrixSolution.h"
#include "../Utils/BFSUtils.h"


class BFS : public Searcher<MatrixSearchable, string> {
  shared_ptr<State<shared_ptr<Point>>> initialState;
  shared_ptr<State<shared_ptr<Point>>> endState;
  MatrixSearchable *matrix;
  shared_ptr<State<shared_ptr<Point>>> solution;

 public:
  BFS(MatrixSearchable* searchble) {
      this->matrix = searchble;
  }

  string Search(MatrixSearchable problem) {
      this->matrix = &problem;
      std::priority_queue<shared_ptr<State<shared_ptr<Point>>>, vector<shared_ptr<State<shared_ptr<Point>>>>, CompareStep<shared_ptr<Point>>> open;
      open.push(problem.GetInitialState());
      std::list<shared_ptr<State<shared_ptr<Point>>>> closed;
      while (!open.empty()) {
          shared_ptr<State<shared_ptr<Point>>> n = open.top();
          open.pop();
          closed.push_back(n);
          if (problem.IsGoalState(n)) {
              this->solution = n;
              break;
          }
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = matrix->GetAllPossiableStates(n);
          for (shared_ptr<State<shared_ptr<Point>>> s: successor) {
              if (!CheckIfValueInSidePriorityQueue(s, open) && !CheckIfValueInsideList(s, closed)) {
                  s->SetComeFrom(n);
                  open.push(s);
              } else {
                  s->SetComeFrom(n);
                  if(CheckIfPathBetterInPriorityQueue(s, open) || CheckIfPathBetterList(s, closed) ) {
                      if (!CheckIfValueInSidePriorityQueue(s, open)) {
                            open.push(s);
                      }
                      else {
                          RemoveValFromPriorityQueueByValue(s, open);
                          open.push(s);
                      }
                  }
              }
          }
      }
      vector<string> a;
      MatrixSolution sol(a,this->solution);
      return sol.ToString();
  }
};
#endif //PROJ2_BFS_H
