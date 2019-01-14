//
// Created by stav on 1/12/19.
//

#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H
#include "MatrixSearchable.h"
#include "MatrixSolution.h"
#include "Searcher.h"
#include <unordered_set>
#include "../Utils/BFSUtils.h"
class DFS : Searcher<shared_ptr<MatrixSearchable>, shared_ptr<MatrixSolution>> {

 public:
  virtual shared_ptr<MatrixSolution> Search(shared_ptr<MatrixSearchable> problem) {
      shared_ptr<State<shared_ptr<Point>>> solution;
      list<shared_ptr<State<shared_ptr<Point>>>> visitedNodes;
      vector<shared_ptr<State<shared_ptr<Point>>>> adjacentPoints;
      stack<shared_ptr<State<shared_ptr<Point>>>> rough;
      bool isRoot = true;
      //initialize start point
      shared_ptr<State<shared_ptr<Point>>> currentNode = problem->GetInitialState();
      while (!(problem->IsGoalState(currentNode))) {
          //get all possiable states to move
          adjacentPoints = problem->GetAllPossiableStates(currentNode);
          bool foundNotVisited = false;
          visitedNodes.push_back(currentNode);
          //loop trought all neighbors of current node
          for (auto point: adjacentPoints) {
              if (!CheckIfValueInsideList(point,visitedNodes)) {
                  rough.push(currentNode);
                  //set its came from
                  point->SetComeFrom(currentNode);
                  visitedNodes.push_back(point);
                  currentNode = point;
                  foundNotVisited = true;
                  break;
              }
          }
          if (foundNotVisited) {
              continue;
          }
          if (rough.empty()) {
              //no trajectory found
              return nullptr;
          }
          currentNode = rough.top();
          rough.pop();
      }
      //reached goal state
      shared_ptr<MatrixSolution> sol = make_shared<MatrixSolution>(currentNode);
      return sol;

  }
};
#endif //PROJ2_DFS_H
