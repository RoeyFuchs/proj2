
#ifndef PROJ2_INPUTSTREAM_H
#define PROJ2_INPUTSTREAM_H
#define MAX_CHARS 1024
#include <iostream>

#include <unistd.h>

class InputStream : public std::istream {
  int newsockfd;

 public:
  InputStream(int newsockfd) {
      this->newsockfd = newsockfd;
  }
  std::string operator>>(void*) {
      const char * a[MAX_CHARS];
      ::read(this->newsockfd, a, MAX_CHARS);
      return std::string(*a);
  }
};

#endif //PROJ2_INPUTSTREAM_H
