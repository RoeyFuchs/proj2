#ifndef PROJ2_MATRIXSOLUTION_H
#define PROJ2_MATRIXSOLUTION_H
#include "Solution.h"
#include "../Utils/Point.h"
#include "State.h"
#include <iostream>
#include <list>
#define SEPARATOR ", "
enum directions {Up, Down, Left, Right};

class MatrixSolution : public Solution<int> {
  shared_ptr<State<shared_ptr<Point>>> finalPoint;
  std::string solution;

 public:
   MatrixSolution(shared_ptr<State<shared_ptr<Point>>> point) {
       this->finalPoint = point;
  }
  MatrixSolution(vector<string> vec) {
       std::string sol;
       for(std::string str : vec) {
           sol += str;
       }
       this->solution = sol;
   }
   /**
    * ToString
    * @return string value of solution
    */
  string ToString() {
      if(this->solution.empty()) {
          this->solution = MakeStringFromState();
      }
      return this->solution;
  }
 private:
  /**
   * MakeStringFromState
   * @return to string of state
   */
  string MakeStringFromState() {
      shared_ptr<State<shared_ptr<Point>>> cuurntPoint = this->finalPoint;
      if (cuurntPoint == nullptr) {
          return "NO SOLUTION";
      }
      std::list<directions> dir;
      while(cuurntPoint->GetCameFrom() != nullptr) {
          if(cuurntPoint->GetState()->getY() != cuurntPoint->GetCameFrom()->GetState()->getY()) {
              if(cuurntPoint->GetState()->getY() > cuurntPoint->GetCameFrom()->GetState()->getY()) {
                  dir.push_back(Down);
              } else {
                  dir.push_back(Up);
              }
          } else {
              if(cuurntPoint->GetState()->getX() > cuurntPoint->GetCameFrom()->GetState()->getX()) {
                  dir.push_back(Right);
              } else {
                  dir.push_back(Left);
              }
          }
          cuurntPoint = cuurntPoint->GetCameFrom();
      }
      return MakeDirectionString(dir);
   }
/**
 * MakeDirectionString
 * @param dir
 * @return string of diresction
 */
  string MakeDirectionString(std::list<directions> dir) {
       std::string str = "{";
       for(auto itr = dir.rbegin(); itr != dir.rend(); ++itr){
           str += addDirectionToString(*itr);
           str += SEPARATOR;
       }
       str = str.substr(0, str.size()-string(SEPARATOR).size());
       str += "}";
       return str;
   }
   /**
 * addDirectionToString
 * @param dir
 * @return string of dirsctinon
 */

  string addDirectionToString(directions dir) {
       switch (dir) {
           case Up:
               return "Up";
               break;
           case Down:
               return "Down";
               break;
           case Left:
               return "Left";
               break;
           case Right:
               return "Right";
               break;
           default:
               throw runtime_error(string("Error while creating string"));
       }
   }

};

#endif //PROJ2_MATRIXSOLUTION_H
