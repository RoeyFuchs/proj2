
#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H
#include "../Server.h"
#include "../Stream/InputStream.h"
#include "../Stream/OutputStream.h"
#define TIMEOUT_SECONDE 30
#define TIMEOUT_MILISECONDE 0
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <sys/socket.h>

class MySerialServer : public Server {
  int sockfd;
  ClientHendler* clientHendler;
  bool active;
 public:

  MySerialServer(){}
  virtual void Open(int port, ClientHendler *clientHendler) {
      this->clientHendler = clientHendler; }
  virtual void Open(int port) {
      int sockfd, newsockfd, clilen;
      struct sockaddr_in serv_addr, cli_addr;
      int n;

      /* First call to socket() function */
      this->sockfd = socket(AF_INET, SOCK_STREAM, 0);

      if (sockfd < 0) {
          throw runtime_error(string("ERROR opening socket"));
      }

      /* Initialize socket structure */
      bzero((char *) &serv_addr, sizeof(serv_addr));

      serv_addr.sin_family = AF_INET;
      serv_addr.sin_addr.s_addr = INADDR_ANY;
      serv_addr.sin_port = htons(port);

      /* Now bind the host address using bind() call.*/
      if (bind(this->sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
          throw runtime_error(string("ERROR on binding"));
      }
      this->active = true;

  }

  void Start() {
      int i = 1;

      struct timeval tv;
      fd_set rfds;
      FD_ZERO(&rfds);
      FD_SET(this->sockfd, &rfds);

      tv.tv_sec = TIMEOUT_SECONDE;
      tv.tv_usec = TIMEOUT_MILISECONDE;

      int newsockfd, clilen, n;
      struct sockaddr_in cli_addr;
      clilen = sizeof(cli_addr);

      //only 1 at time - serial server
      listen(this->sockfd, 1);
      while(this->active && select(this->sockfd + 1, &rfds, nullptr, nullptr, &tv)) {

          /* Accept actual connection from the client */
          newsockfd = accept(this->sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
          if (newsockfd < 0) {
              throw runtime_error(string("ERROR on accept"));
          }

          /* Write a response to the client */
          OutputStream outStream (newsockfd);
          InputStream inputStream(newsockfd);
          this->clientHendler->HandleClient(inputStream, outStream);
      }
      close(this->sockfd);
  }
  virtual void Stop() {
      this->active = false;
  }
};

#endif //PROJ2_MYSERIALSERVER_H
