#ifndef PROJ2_PARALLEL_H
#define PROJ2_PARALLEL_H

#include "../Server.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <sys/socket.h>
#include <thread>
#define TIMEOUT_SECONDE 20
#define TIMEOUT_MILISECONDE 0
class MyParallelServer : public server_side::Server {
  int sockfd;
  ClientHendler *clientHendler;
  bool active;
  vector<thread> threadList;
 public:

  MyParallelServer() = default;
/**
 * Open
 * @param port
 * @param clientHendler
 * the function opens socket for new client hendler
 */
  virtual void Open(int port, ClientHendler *clientHendler) {
      this->clientHendler = clientHendler;
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
/**
 * start- open a thread to server client stream
 */
  void Start() {
      //open a thread to server-client stream
      thread t1(&MyParallelServer::MakeConnection, this);
      t1.join();
  }
/**
 * MakeConnection- create connection with client
 */
  void MakeConnection() {
      listen(this->sockfd, SOMAXCONN);

      int newsockfd, clilen, n;
      struct sockaddr_in cli_addr;
      clilen = sizeof(cli_addr);
      struct timeval tv;
      fd_set rfds;
      FD_ZERO(&rfds);
      FD_SET(this->sockfd, &rfds);
      //set a timeout timer
      tv.tv_sec = TIMEOUT_SECONDE;
      tv.tv_usec = TIMEOUT_MILISECONDE;
      while (this->active && select(this->sockfd + 1, &rfds, nullptr, nullptr, &tv)) {
          FD_ZERO(&rfds);
          FD_SET(this->sockfd, &rfds);
          /* Accept actual connection from the client */
          newsockfd = accept(this->sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
          if (newsockfd < 0) {
              throw runtime_error(string("ERROR on accept"));
          }

          /* Write a response to the client */
          shared_ptr<OutputStream> outStream = make_shared<OutputStream>(newsockfd);
          shared_ptr<InputStream> inputStream = make_shared<InputStream>(newsockfd);
          thread t1(&MyParallelServer::StartCliendHandlerThread, this, inputStream, outStream);
          this->threadList.push_back(std::move(t1));
      }
      for (int i = 0; i < this->threadList.size(); ++i) {
          this->threadList.at(i).join();
      }
  }

  void StartCliendHandlerThread(shared_ptr<InputStream> in, shared_ptr<OutputStream> out) {
      this->clientHendler->HandleClient(*in.get(), *out.get());
  }
/**
 * Stop th server
 */
  virtual void Stop() {
      this->active = false;
      close(this->sockfd);
  }
};

#endif //PROJ2_PARALLEL_H
