
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
  shared_ptr<State<shared_ptr<Point>>> solution;
  int visited;

 public:
  BFS() = default;

  string Search(MatrixSearchable problem) {
      this->solution = nullptr;
      this->visited = 0;
      std::priority_queue<shared_ptr<State<shared_ptr<Point>>>, vector<shared_ptr<State<shared_ptr<Point>>>>, CompareStep<shared_ptr<Point>>> open;
      open.push(problem.GetInitialState());
      std::list<shared_ptr<State<shared_ptr<Point>>>> closed;
      while (!open.empty()) {
          this->visited++;
          shared_ptr<State<shared_ptr<Point>>> n = open.top();
          open.pop();
          closed.push_back(n);
          if (problem.IsGoalState(n)) {
              this->solution = n;
              break;
          }
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = problem.GetAllPossiableStates(n);
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
      cout << "BFS: " << this->solution->GetPathCost()<<","<< this->visited << endl;
      MatrixSolution sol(this->solution);
      return sol.ToString();
  }

  string SearchCOP(MatrixSearchable problem, ostream* ostream) {
      this->solution = nullptr;
      this->visited = 0;
      std::priority_queue<shared_ptr<State<shared_ptr<Point>>>, vector<shared_ptr<State<shared_ptr<Point>>>>, CompareStep<shared_ptr<Point>>> open;
      open.push(problem.GetInitialState());
      std::list<shared_ptr<State<shared_ptr<Point>>>> closed;
      while (!open.empty()) {
          this->visited++;
          shared_ptr<State<shared_ptr<Point>>> n = open.top();
          open.pop();
          closed.push_back(n);
          if (problem.IsGoalState(n)) {
              this->solution = n;
              break;
          }
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = problem.GetAllPossiableStates(n);
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
      *ostream << "BFS: " << this->solution->GetPathCost()<<","<< this->visited << endl;
      MatrixSolution sol(this->solution);
      return sol.ToString();
  }
};
#endif //PROJ2_BFS_H
