
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

class BFS : public Searcher<vector<vector<int>>, string> {
  shared_ptr<State<Point>> initialState;
  shared_ptr<State<Point>> endState;
  MatrixSearchable *matrix;

  string Search(MatrixSearchable problem) {
      std::priority_queue<shared_ptr<State<Point>>, vector<shared_ptr<State<Point>>>, CompareStep> open;
      open.push(this->initialState);
      std::list<shared_ptr<State<Point>>> closed;
      while (!open.empty()) {
          shared_ptr<State<Point>> n = open.top();
          open.pop();
          closed.push_back(n);
          if (n == this->endState) {
              //n->GetPath();
          }
          vector<shared_ptr<State<Point>>> successor = matrix->GetAllPossiableStates(n);
          for (auto s: successor) {
              bool foundInClosed = (std::find(closed.begin(), closed.end(), s) != closed.end());
              if (!CheckIfValueInSidePriorityQueue<shared_ptr<State<Point>>>(s, open) && foundInClosed) {
                  s->SetComeFrom(n);
                  open.push(s);
              }
              closed.push_back(n);
          }

      }

  };
#endif //PROJ2_BFS_H
