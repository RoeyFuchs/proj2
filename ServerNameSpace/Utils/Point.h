
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

  int getX() const{
      return this->x;
  }
  int getY() const {
      return this->y;
  }

  bool operator==(const Point& point) const {
      return (this->getX() == point.getX() && this->getY() == point.getY());
  }
  bool operator<(const Point p) const {
      return (this->getX()+this->getY() < p.getX()+p.getY());
  }
};

#endif //PROJ2_POINT_H
