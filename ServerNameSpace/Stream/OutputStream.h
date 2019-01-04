
#ifndef PROJ2_OUTPUTSTREAM_H
#define PROJ2_OUTPUTSTREAM_H
#include <iostream>

#include <unistd.h>
class OutputStream : public std::ostream {
  int newsockfd;
 public:
  OutputStream(int newsockfd) {
      this->newsockfd = newsockfd;
  }
  OutputStream &operator<<(const char* arr) {
      std::string str(arr);
      ::write(this->newsockfd, str.c_str(), str.length());
      return *this;
  }
  OutputStream &operator<<(std::string str) {
      ::write(this->newsockfd, str.c_str(), str.length());
      return *this;
  }

};
#endif //PROJ2_OUTPUTSTREAM_H
