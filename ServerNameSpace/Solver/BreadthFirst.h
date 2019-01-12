#ifndef PROJ2_BREADTHFIRST_H
#define PROJ2_BREADTHFIRST_H

#include <map>
#include "State.h"
#include "MatrixSearchable.h"
#include "MatrixSolution.h"
class BreadthFirst {
  shared_ptr<State<shared_ptr<Point>>> initialState;
  shared_ptr<State<shared_ptr<Point>>> endState;
  MatrixSearchable *matrix;
  shared_ptr<State<shared_ptr<Point>>> solution;

 public:
  BreadthFirst(MatrixSearchable* searchble) {
      this->matrix = searchble;
  }

  string Search(MatrixSearchable problem) {
      map<Point, bool> discovered;
      discovered[*problem.GetInitialState()->GetState().get()] = true;
      queue<shared_ptr<State<shared_ptr<Point>>>> q;
      q.push(problem.GetInitialState());

      while(!q.empty()) {
          auto curr = q.front();
          q.pop();
          if (problem.IsGoalState(curr)) {
              this->solution = curr;
              break;
          }
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = matrix->GetAllPossiableStates(curr);
          for(auto children : successor) {
              if (!discovered[*children->GetState().get()]) {
                  discovered[*children->GetState().get()] = true;
                  children->SetComeFrom(curr);
                  q.push(children);
              }
          }
      }
      MatrixSolution sol(this->solution);
      return sol.ToString();
  }

};

#endif //PROJ2_BREADTHFIRST_H
