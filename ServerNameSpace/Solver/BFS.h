
#ifndef PROJ2_BFS_H
#define PROJ2_BFS_H

#include <queue>
#include <list>
#include <algorithm>
#include "Searcher.h"
#include "Solution.h"
#include "../Utils/Comperators.h"
#include "../Utils/Utils.h"
#include "MatrixSearchable.h"

class BFS : public Searcher<MatrixSearchable, string> {
  shared_ptr<State<shared_ptr<Point>>> initialState;
  shared_ptr<State<shared_ptr<Point>>> endState;
  MatrixSearchable *matrix;

 public:
  BFS(MatrixSearchable* searchble) {
      this->matrix = searchble;
  }

  string Search(MatrixSearchable problem) {
      std::priority_queue<shared_ptr<State<shared_ptr<Point>>>, vector<shared_ptr<State<shared_ptr<Point>>>>, CompareStep<Point>> open;
      open.push(this->initialState);
      std::list<shared_ptr<State<shared_ptr<Point>>>> closed;
      while (!open.empty()) {
          shared_ptr<State<shared_ptr<Point>>> n = open.top();
          open.pop();
          closed.push_back(n);
          if (n == this->endState) {
              cout << "DONE" << endl;

              //n->GetPath();
          }
          vector<shared_ptr<State<shared_ptr<Point>>>> successor = matrix->GetAllPossiableStates(n);
          for (shared_ptr<State<shared_ptr<Point>>> s: successor) {
              bool foundInClosed = (std::find(closed.begin(), closed.end(), s) != closed.end());
              if (CheckIfValueInSidePriorityQueue<shared_ptr<State<shared_ptr<Point>>>>(s, open) && foundInClosed) {
                  s->SetComeFrom(n);
                  open.push(s);
              }
              closed.push_back(n);
          }

      }
  }
  };
#endif //PROJ2_BFS_H
