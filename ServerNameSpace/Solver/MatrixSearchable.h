
#ifndef PROJ2_MATRIXSEARCHABLE_H
#define PROJ2_MATRIXSEARCHABLE_H

#include "Searchable.h"
#include "../Utils/Point.h"
#include <vector>
#include <tuple>
#include <memory>
#include <iostream>
#define UNDERLINE '/n'
class MatrixSearchable : public Searchable<shared_ptr<Point>> {
  vector<string> initialState;
  shared_ptr<Point> startPoint;
  shared_ptr<Point> endPoint;
  shared_ptr<Point> currentPos;
  vector<vector<int>> matrix;
  int size;
 public:

  MatrixSearchable(vector<string> &vec) : Searchable(vec) {
      this->initialState = vec;
      this->size = stoi(vec.at(0));
      string startingPoint = vec.at(1);
      int startXPosition = startingPoint.find(",");
      int startX = stoi(startingPoint.substr(0, startXPosition));
      int startY = stoi(startingPoint.substr(startXPosition, startingPoint.length() - 1));
      string endingPoint = vec.at(2);
      int endXPosition = endingPoint.find(",");
      int endX = stoi(endingPoint.substr(0, endXPosition));
      int endY = stoi(endingPoint.substr(endXPosition, endingPoint.length() - 1));

      this->startPoint = make_shared<Point>(startX, startY);
      this->endPoint = make_shared<Point>(endX, endY);
    /*
     * todo
     */
      //convert string metrix into int

  }
  virtual string ToString() {
      string str;
      for (int i = 0; i < this->initialState.size(); i++) {
          str = str + this->initialState.at(i);
          str += UNDERLINE;
      }
  }

  State<shared_ptr<Point>> GetInitialState() {
      return this->startPoint;
  }
  virtual bool IsGoalState(shared_ptr<State<Point>> state) {
      return state->GetState() == *(this->endPoint.get());
  }
  virtual vector<shared_ptr<State<Point>>> GetAllPossiableStates(State<Point> s) {
      vector<shared_ptr<State<Point>>> states;
      for (int y = s.GetState().getY()-1; y < s.GetState().getY() + 2; y++) {
          for(int x = s.GetState().getX()-1 ; x < s.GetState().getX() +2 ; x++) {
              if(x > 0 && x < this->size && y > 0 && y < this->size) {
                  shared_ptr<State<Point>> p = make_shared<State<Point>>(x, y);
                  states.push_back(p);
              }
          }
      }
      return states;
  }

};

#endif //PROJ2_MATRIXSEARCHABLE_H
