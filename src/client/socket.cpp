#include "socket.h"

void Socket::SendMessage(const std::string &message) {
  // Create socket
  sock_ = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_ < 0) {
    std::cerr << "Socket creation error: " << strerror(errno) << std::endl;
  }

  serv_addr_.sin_family = AF_INET;
  serv_addr_.sin_port = htons(8080);

  // Cast IP to binary from string
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr_.sin_addr) <= 0) {
    std::cerr << "Invalid address: " << strerror(errno) << std::endl;
    close(sock_);
    return;
  }

  // Trying to connect to server
  if (connect(sock_, (struct sockaddr *)&serv_addr_, sizeof(serv_addr_)) < 0) {
    std::cerr << "Connection failed: " << strerror(errno) << std::endl;
    close(sock_);
    return;
  }

  // Sending message to server
  if (send(sock_, message.c_str(), strlen(message.c_str()), 0) < 0) {
    std::cerr << "Send failed: " << strerror(errno) << std::endl;
  }

  // Close socket
  close(sock_);
}
