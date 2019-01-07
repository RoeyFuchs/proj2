
#ifndef PROJ2_POINT_H
#define PROJ2_POINT_H
class Point{
  int x;
  int y;

 public:
  Point(int x, int y) {
      this->x = x;
      this->y = y;
  }

  int getX(){
      return this->x;
  }
  int getY() {
      return this->y;
  }

  bool operator==(Point& point) {
      return (this->getX() == point.getX() && this->getY() == point.getY());
  }
};

#endif //PROJ2_POINT_H
