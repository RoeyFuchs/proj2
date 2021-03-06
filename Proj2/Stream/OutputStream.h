
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
  /**
   * << read char* into outputstream
   * @param arr
   * @return  outputstream
   */
  OutputStream &operator<<(const char* arr) {
      std::string str(arr);
      ::write(this->newsockfd, str.c_str(), str.length());
      return *this;
  }
  /**
   * >> read string into outputstream
   * @param str
   * @return outputstream
   */
  OutputStream &operator<<(std::string str) {
      ::write(this->newsockfd, str.c_str(), str.length());
      return *this;
  }

};
#endif //PROJ2_OUTPUTSTREAM_H
