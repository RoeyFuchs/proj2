
#ifndef PROJ2_MATRIXSEARCHABLE_H
#define PROJ2_MATRIXSEARCHABLE_H

#include "Searchable.h"
#include "../Utils/Utils.h"
#include <vector>
#include <tuple>
#include <memory>
#include <iostream>
#define UNDERLINE '\n'
#define WALL -1
class MatrixSearchable : public Searchable<shared_ptr<Point>> {
  vector<string> initialState;
  shared_ptr<Point> startPoint;
  shared_ptr<Point> endPoint;
  shared_ptr<Point> currentPos;
  vector<vector<int>> matrix;
  int sizeRows;
  int sizeCulm;
 public:
/**
 * MatrixSearchable
 * @param vec
 * constructor
 */
  MatrixSearchable(vector<string> &vec) : Searchable(vec) {
      this->initialState = vec;
      string startingPoint = vec.at(vec.size() - 2);
      int startXPosition = startingPoint.find(",");
      int startX = stoi(startingPoint.substr(0, startXPosition));
      int startY = stoi(startingPoint.substr(startXPosition + 1, startingPoint.length() - 1));
      string endingPoint = vec.at(vec.size() - 1);
      int endXPosition = endingPoint.find(",");
      int endX = stoi(endingPoint.substr(0, endXPosition));
      int endY = stoi(endingPoint.substr(endXPosition+1, endingPoint.length() - 1));

      this->startPoint = make_shared<Point>(startX, startY);
      this->endPoint = make_shared<Point>(endX, endY);

      vector<string> matrixInString = Slice(vec, 0, vec.size()-3);
      this->matrix = ConvertStringToMatrix(matrixInString);
      this->sizeRows = this->matrix.size();
      this->sizeCulm = this->matrix.at(0).size();

  }
  /**
   * create string with the matrix
   * @return the string
   */
  virtual string ToString() {
      string str;
      for (int i = 0; i < this->initialState.size(); i++) {
          str = str + this->initialState.at(i);
          str += UNDERLINE;
      }
      return str;
  }
/**
 * create the start point
 * @return return the state of the stare
 */
  shared_ptr<State<shared_ptr<Point>>> GetInitialState() {
      shared_ptr<State<shared_ptr<Point>>> a = make_shared<State<shared_ptr<Point>>>(this->startPoint);
      a->SetCost(this->matrix.at(a->GetState()->getY()).at(a->GetState()->getX()));
      return a;
  }
  /**
   * IsGoalState
   * @param state
   * @return true if current state is goal state or false otherwise
   */
  virtual bool IsGoalState(shared_ptr<State<shared_ptr<Point>>> state) {
      return *(state->GetState()) == *(this->endPoint.get());
  }
  /**
   * GetAllPossiableStates
   * @param s
   * @return returns al posibbol states according to current state
   */
  virtual vector<shared_ptr<State<shared_ptr<Point>>>> GetAllPossiableStates(shared_ptr<State<shared_ptr<Point>>> s) {
      vector<shared_ptr<State<shared_ptr<Point>>>> states;
      //up value
      if (s->GetState()->getY() -1 >= 0) {
          shared_ptr<Point> p = make_shared<Point>(s->GetState()->getX(), s->GetState()->getY() -1);
          shared_ptr<State<shared_ptr<Point>>> state = make_shared<State<shared_ptr<Point>>>(p);
          double cost = this->matrix.at(s->GetState()->getY()-1).at(s->GetState()->getX());
          if(IsCostValid(cost)) {
              state->SetCost(cost);
              states.push_back(state);
          }
      }
      //down value
      if (s->GetState()->getY() + 1 < this->sizeRows) {
          shared_ptr<Point> p = make_shared<Point>(s->GetState()->getX(), s->GetState()->getY() +1);
          shared_ptr<State<shared_ptr<Point>>> state = make_shared<State<shared_ptr<Point>>>(p);
          double cost = this->matrix.at(s->GetState()->getY()+1).at(s->GetState()->getX());
          if(IsCostValid(cost)) {
              state->SetCost(cost);
              states.push_back(state);
          }
      }
      //left value
      if (s->GetState()->getX() -1 >= 0) {
          shared_ptr<Point> p = make_shared<Point>(s->GetState()->getX() -1, s->GetState()->getY());
          shared_ptr<State<shared_ptr<Point>>> state = make_shared<State<shared_ptr<Point>>>(p);
          double cost = this->matrix.at(s->GetState()->getY()).at(s->GetState()->getX() - 1);
          if(IsCostValid(cost)) {
              state->SetCost(cost);
              states.push_back(state);
          }
      }
      //right value
      if (s->GetState()->getX() + 1 < this->sizeCulm) {
          shared_ptr<Point> p = make_shared<Point>(s->GetState()->getX() +1, s->GetState()->getY());
          shared_ptr<State<shared_ptr<Point>>> state = make_shared<State<shared_ptr<Point>>>(p);
          double cost = this->matrix.at(s->GetState()->getY()).at(s->GetState()->getX() + 1);
          if(IsCostValid(cost)) {
              state->SetCost(cost);
              states.push_back(state);
          }
      }
      return states;
  }
/**
 * IsCostValid
 * @param cost
 * @return true if cost is valid or false otherwise
 */
  bool IsCostValid(double cost) {
      if(cost != WALL) {
          return true;
      }
      return false;
  }
/**
 * GetEndPoint
 * @return  end point
 */
  shared_ptr<State<shared_ptr<Point>>> GetEndPoint() {
      return make_shared<State<shared_ptr<Point>>>(this->endPoint);;
  }
/**
 * GetMatrix
 * @return  matrix
 */
  vector<vector<int>> GetMatrix() {
      return this->matrix;
  }

};

#endif //PROJ2_MATRIXSEARCHABLE_H
