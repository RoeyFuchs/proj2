
#ifndef PROJ2_MATRIXSEARCHABLE_H
#define PROJ2_MATRIXSEARCHABLE_H

#include "Searchable.h"
#include "../Utils/Utils.h"
#include <vector>
#include <tuple>
#include <memory>
#include <iostream>
#define UNDERLINE '\n'
class MatrixSearchable : public Searchable<shared_ptr<Point>> {
  vector<string> initialState;
  shared_ptr<Point> startPoint;
  shared_ptr<Point> endPoint;
  shared_ptr<Point> currentPos;
  vector<vector<int>> matrix;
  int sizeRows;
  int sizeCulm;
 public:

  MatrixSearchable(vector<string> &vec) : Searchable(vec) {
      this->initialState = vec;
      this->sizeRows = stoi(vec.at(0));
      this->sizeCulm = stoi(vec.at(0));
      string startingPoint = vec.at(1);
      int startXPosition = startingPoint.find(",");
      int startX = stoi(startingPoint.substr(0, startXPosition));
      int startY = stoi(startingPoint.substr(startXPosition + 1, startingPoint.length() - 1));
      string endingPoint = vec.at(2);
      int endXPosition = endingPoint.find(",");
      int endX = stoi(endingPoint.substr(0, endXPosition));
      int endY = stoi(endingPoint.substr(endXPosition+1, endingPoint.length() - 1));

      this->startPoint = make_shared<Point>(startX, startY);
      this->endPoint = make_shared<Point>(endX, endY);

      vector<string> matrixInString = Slice(vec, 3, vec.size()-1);
      this->matrix = ConvertStringToMatrix(matrixInString);


  }
  virtual string ToString() {
      string str;
      for (int i = 0; i < this->initialState.size(); i++) {
          str = str + this->initialState.at(i);
          str += UNDERLINE;
      }
      return str;
  }

  shared_ptr<State<shared_ptr<Point>>> GetInitialState() {
      shared_ptr<State<shared_ptr<Point>>> a = make_shared<State<shared_ptr<Point>>>(this->startPoint);
      return a;
  }
  virtual bool IsGoalState(shared_ptr<State<shared_ptr<Point>>> state) {
      return *(state->GetState()) == *(this->endPoint.get());
  }
  virtual vector<shared_ptr<State<shared_ptr<Point>>>> GetAllPossiableStates(shared_ptr<State<shared_ptr<Point>>> s) {
      vector<shared_ptr<State<shared_ptr<Point>>>> states;
      //up value
      if (s->GetState()->getY() -1 >= 0) {
          shared_ptr<Point> p = make_shared<Point>(s->GetState()->getX(), s->GetState()->getY() -1);
          shared_ptr<State<shared_ptr<Point>>> state = make_shared<State<shared_ptr<Point>>>(p);
          states.push_back(state);
      }
      //down value
      if (s->GetState()->getY() + 1 < this->sizeRows) {
          shared_ptr<Point> p = make_shared<Point>(s->GetState()->getX(), s->GetState()->getY() +1);
          shared_ptr<State<shared_ptr<Point>>> state = make_shared<State<shared_ptr<Point>>>(p);
          states.push_back(state);
      }
      //left value
      if (s->GetState()->getX() -1 >= 0) {
          shared_ptr<Point> p = make_shared<Point>(s->GetState()->getX() -1, s->GetState()->getY());
          shared_ptr<State<shared_ptr<Point>>> state = make_shared<State<shared_ptr<Point>>>(p);
          states.push_back(state);
      }
      //right value
      if (s->GetState()->getX() + 1 < this->sizeCulm) {
          shared_ptr<Point> p = make_shared<Point>(s->GetState()->getX() +1, s->GetState()->getY());
          shared_ptr<State<shared_ptr<Point>>> state = make_shared<State<shared_ptr<Point>>>(p);
          states.push_back(state);
      }
      return states;
  }

};

#endif //PROJ2_MATRIXSEARCHABLE_H
