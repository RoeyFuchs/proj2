#ifndef PROJ2_MATRIXSOLUTION_H
#define PROJ2_MATRIXSOLUTION_H
#include "Solution.h"
#include "../Utils/Point.h"
#include "State.h"
#define SEPARATOR ", "
enum directions {Up, Down, Left, Right};

class MatrixSolution : public Solution<int> {
  shared_ptr<State<shared_ptr<Point>>> finalPoint;

 public:

   MatrixSolution(vector<string> &vec, shared_ptr<State<shared_ptr<Point>>> point) : finalPoint(point), Solution(vec)  {
  }
  string ToString() {
      shared_ptr<State<shared_ptr<Point>>> cuurntPoint = this->finalPoint;
      if (cuurntPoint == nullptr) {
          return "NO SOLUTION";
      }
      directions direction;
      string path = "{";
      bool first = true;
      while(cuurntPoint->GetCameFrom() != nullptr) {
          if(cuurntPoint->GetState()->getY() != cuurntPoint->GetCameFrom()->GetState()->getY()) {
              if(cuurntPoint->GetState()->getY() > cuurntPoint->GetCameFrom()->GetState()->getY()) {
                  direction = Down;
              } else {
                  direction = Up;
              }
          } else {
              if(cuurntPoint->GetState()->getX() > cuurntPoint->GetCameFrom()->GetState()->getX()) {
                  direction = Right;
              } else {
                  direction = Left;
              }
          }
          path = addDirectionToString(direction, path, first);
          cuurntPoint = cuurntPoint->GetCameFrom();
          first = false;
      }
      path += "}";
      return path;
  }

  string addDirectionToString(directions dir, string str, bool first) {
       if(!first) {
           str += SEPARATOR;
       }
       switch (dir) {
           case Up:
               str += "Up";
               break;
           case Down:
               str += "Down";
               break;
           case Left:
               str += "Left";
               break;
           case Right:
               str += "Right";
               break;
           default:
               throw runtime_error(string("Error while creating string"));
       }
       return str;
   }

};

#endif //PROJ2_MATRIXSOLUTION_H
