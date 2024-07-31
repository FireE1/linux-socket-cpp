#pragma once

#include <arpa/inet.h>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

struct Socket {

  void SendMessage(const std::string &message);

  int sock_ = 0;
  struct sockaddr_in serv_addr_;
};
