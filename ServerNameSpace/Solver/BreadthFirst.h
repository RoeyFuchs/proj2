#ifndef PROJ2_BREADTHFIRST_H
#define PROJ2_BREADTHFIRST_H

#include <map>
#include "State.h"
#include "MatrixSearchable.h"
#include "MatrixSolution.h"
class BreadthFirst {
  int visited;
  shared_ptr<State<shared_ptr<Point>>> solution;

 public:
  BreadthFirst() = default;

  string Search(MatrixSearchable problem) {
      this->visited = 0;
      this->solution = nullptr;
      map<Point, bool> discovered;
      discovered[*problem.GetInitialState()->GetState().get()] = true;
      queue<shared_ptr<State<shared_ptr<Point>>>> q;
      q.push(problem.GetInitialState());

      while (!q.empty()) {
          this->visited++;
          auto curr = q.front();
          q.pop();
          if (problem.IsGoalState(curr)) {
              this->solution = curr;
              break;
          }
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = problem.GetAllPossiableStates(curr);
          for (auto children : successor) {
              if (!discovered[*children->GetState().get()]) {
                  discovered[*children->GetState().get()] = true;
                  children->SetComeFrom(curr);
                  q.push(children);
              }
          }
      }
      cout<< "BreadthFS: " << this->solution->GetPathCost()<<","<< this->visited << endl;
      MatrixSolution sol(this->solution);
      return sol.ToString();
  }

  string SearchCOP(MatrixSearchable problem, ostream* ostream) {
      this->visited = 0;
      this->solution = nullptr;
      map<Point, bool> discovered;
      discovered[*problem.GetInitialState()->GetState().get()] = true;
      queue<shared_ptr<State<shared_ptr<Point>>>> q;
      q.push(problem.GetInitialState());

      while (!q.empty()) {
          this->visited++;
          auto curr = q.front();
          q.pop();
          if (problem.IsGoalState(curr)) {
              this->solution = curr;
              break;
          }
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = problem.GetAllPossiableStates(curr);
          for (auto children : successor) {
              if (!discovered[*children->GetState().get()]) {
                  discovered[*children->GetState().get()] = true;
                  children->SetComeFrom(curr);
                  q.push(children);
              }
          }
      }
      *ostream << "BreadthFS: " << this->solution->GetPathCost()<<","<< this->visited << endl;
      MatrixSolution sol(this->solution);
      return sol.ToString();
  }

};

#endif //PROJ2_BREADTHFIRST_H
