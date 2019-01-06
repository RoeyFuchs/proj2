
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
  void operator>>(std::string& str) {
      char buffer[MAX_CHARS] = {};
      ::read(this->newsockfd, buffer, MAX_CHARS);
      str = std::string(buffer);
  }
};

#endif //PROJ2_INPUTSTREAM_H
