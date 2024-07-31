#pragma once

#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

class Server {
public:
  Server() = default;
  ~Server();

  // Main loop method
  void Run();

private:
  const bool CreateSocket();
  const bool ClientConnect();
  const std::string RecieveMessage() const;
  void ProcessMessage(const std::string &message);

private:
  bool active_socket_ = false;
  int server_fd_, new_socket_;
  struct sockaddr_in address_;
  int addrlen_ = sizeof(address_);
};
