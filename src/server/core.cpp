#include "core.h"

Server::~Server() {
  if (active_socket_) {
    close(server_fd_);
  }
}

void Server::Run() {
  // Trying to create socket
  while (!CreateSocket()) {
  }
  // Main loop
  while (true) {
    if (!ClientConnect()) {
      continue;
    }
    ProcessMessage(RecieveMessage());
  }
}

const bool Server::CreateSocket() {
  // Create socket
  server_fd_ = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd_ < 0) {
    return false;
  }

  address_.sin_family = AF_INET;
  address_.sin_addr.s_addr = INADDR_ANY;
  address_.sin_port = htons(8080);

  // Link socket to port
  if (bind(server_fd_, (struct sockaddr *)&address_, sizeof(address_)) < 0) {
    close(server_fd_);
    return false;
  }

  // Listen port
  if (listen(server_fd_, 3) < 0) {
    close(server_fd_);
    return false;
  }

  active_socket_ = true;

  return true;
}

const bool Server::ClientConnect() {
  // Wait client to connect
  new_socket_ =
      accept(server_fd_, (struct sockaddr *)&address_, (socklen_t *)&addrlen_);
  if (new_socket_ < 0) {
    return false;
  }

  return true;
}

const std::string Server::RecieveMessage() const {
  char buffer[1024] = {0};
  int valread = read(new_socket_, buffer, 1024);
  return valread < 0 ? "" : std::string(buffer);
}

void Server::ProcessMessage(const std::string &message) {
  if (message.size() < 2 || std::stoi(message) % 32 != 0) {
    std::cerr << "Message Error!" << std::endl;
    return;
  }

  std::cout << "Message accepted: " << message << "\n";
}
