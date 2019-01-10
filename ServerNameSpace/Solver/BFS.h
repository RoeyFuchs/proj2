
#ifndef PROJ2_BFS_H
#define PROJ2_BFS_H

#include <queue>
#include <list>
#include <algorithm>
#include "Searcher.h"
#include "Solution.h"
#include "MatrixSearchable.h"


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
      std::priority_queue<shared_ptr<State<shared_ptr<Point>>>, vector<shared_ptr<State<shared_ptr<Point>>>>, CompareStep<shared_ptr<Point>>> open;
      open.push(this->initialState);
      std::list<shared_ptr<State<shared_ptr<Point>>>> closed;
      while (!open.empty()) {
          shared_ptr<State<shared_ptr<Point>>> n = open.top();
          open.pop();
          closed.push_back(n);
          if (n == this->endState) {
              this->solution = n;
              return this->GetSoulutionString();
          }
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = matrix->GetAllPossiableStates(n);
          for (shared_ptr<State<shared_ptr<Point>>> s: successor) {
              bool foundInClosed = (std::find(closed.begin(), closed.end(), s) != closed.end());
              if (!CheckIfValueInSidePriorityQueue(s, open) && foundInClosed) {
                  s->SetComeFrom(n);
                  open.push(s);
              }
              closed.push_back(n);
          }

      }
  }

  string GetSoulutionString() {
      shared_ptr<State<shared_ptr<Point>>> cuurntPoint = this->solution;
      string path = "{";
      while(cuurntPoint->GetCameFrom() != nullptr) {
          if(cuurntPoint->GetState()->getY() != cuurntPoint->GetCameFrom()->GetState()->getY()) {
              if(cuurntPoint->GetState()->getY() > cuurntPoint->GetCameFrom()->GetState()->getY()) {
                  path += "Down";
              } else {
                  path += "Up";
              }
          } else {
              if(cuurntPoint->GetState()->getX() > cuurntPoint->GetCameFrom()->GetState()->getX()) {
                  path += "Right";
              } else {
                  path += "Left";
              }
          }
      }
      path += "}";
      return path;
  }
};
#endif //PROJ2_BFS_H
