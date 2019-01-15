
#ifndef PROJ2_INPUTSTREAM_H
#define PROJ2_INPUTSTREAM_H
#define MAX_CHARS 1024
#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#define NEW_LINE '\n'

class InputStream : public std::istream {
  int newsockfd;
  std::string buff;

 public:
  InputStream(int newsockfd) {
      this->newsockfd = newsockfd;
  }
  void operator>>(std::string& str) {
      char buffer[MAX_CHARS] = {};
      if(buff.empty()) {
          ::read(this->newsockfd, buffer, MAX_CHARS);
      }
      str = this->buff;
      str += std::string(buffer);
      for(int i = 0; i < str.size(); ++i) {
          if(str.at(i) == NEW_LINE) {
              this->buff = str.substr(i+1, str.size()-1);
              str = str.substr(0, i);
              return;
          }
      }
  }
};

#endif //PROJ2_INPUTSTREAM_H
