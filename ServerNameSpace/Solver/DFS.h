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
  int visited;

 public:
  DFS() = default;

  virtual shared_ptr<MatrixSolution> Search(shared_ptr<MatrixSearchable> problem) {
      this->visited = 0;
      shared_ptr<State<shared_ptr<Point>>> solution;
      list<shared_ptr<State<shared_ptr<Point>>>> visitedPoints;
      vector<shared_ptr<State<shared_ptr<Point>>>> adjacentPoints;
      stack<shared_ptr<State<shared_ptr<Point>>>> rough;
      bool isRoot = true;
      //initialize start point
      shared_ptr<State<shared_ptr<Point>>> currentPoint = problem->GetInitialState();
      while (!(problem->IsGoalState(currentPoint))) {
          this->visited++;
          //get all possiable states to move
          adjacentPoints = problem->GetAllPossiableStates(currentPoint);
          bool foundNotVisited = false;
          visitedPoints.push_back(currentPoint);
          //loop trought all neighbors of current node
          for (auto point: adjacentPoints) {
              if (!CheckIfValueInsideList(point,visitedPoints)) {
                  rough.push(currentPoint);
                  //set its came from
                  point->SetComeFrom(currentPoint);
                  visitedPoints.push_back(point);
                  currentPoint = point;
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
          currentPoint = rough.top();
          rough.pop();
      }
      cout<< "DFS: " << currentPoint->GetPathCost()<<","<< this->visited << endl;
      //reached goal state
      shared_ptr<MatrixSolution> sol = make_shared<MatrixSolution>(currentPoint);
      return sol;

  }

  virtual shared_ptr<MatrixSolution> SearchCOP(shared_ptr<MatrixSearchable> problem, ostream* ostream) {
      this->visited = 0;
      shared_ptr<State<shared_ptr<Point>>> solution;
      list<shared_ptr<State<shared_ptr<Point>>>> visitedPoints;
      vector<shared_ptr<State<shared_ptr<Point>>>> adjacentPoints;
      stack<shared_ptr<State<shared_ptr<Point>>>> rough;
      bool isRoot = true;
      //initialize start point
      shared_ptr<State<shared_ptr<Point>>> currentPoint = problem->GetInitialState();
      while (!(problem->IsGoalState(currentPoint))) {
          this->visited++;
          //get all possiable states to move
          adjacentPoints = problem->GetAllPossiableStates(currentPoint);
          bool foundNotVisited = false;
          visitedPoints.push_back(currentPoint);
          //loop trought all neighbors of current node
          for (auto point: adjacentPoints) {
              if (!CheckIfValueInsideList(point,visitedPoints)) {
                  rough.push(currentPoint);
                  //set its came from
                  point->SetComeFrom(currentPoint);
                  visitedPoints.push_back(point);
                  currentPoint = point;
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
          currentPoint = rough.top();
          rough.pop();
      }
      *ostream<< "DFS: " << currentPoint->GetPathCost()<<","<< this->visited << endl;
      //reached goal state
      shared_ptr<MatrixSolution> sol = make_shared<MatrixSolution>(currentPoint);
      return sol;

  }
};
#endif //PROJ2_DFS_H
