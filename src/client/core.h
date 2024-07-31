#pragma once

#include "data_buffer.h" // Data buffer
#include "socket.h"      // Socket

#include <algorithm>
#include <cctype>
#include <chrono>
#include <iostream>
#include <mutex>
#include <numeric>
#include <ostream>
#include <string>
#include <thread>
#include <vector>

class Client {
public:
  // Reader and sender loops
  void ReaderLoop();
  void SenderLoop();

private:
  // Main reader and sender methods
  void Reader();
  void Sender();

private:
  // Data buffer
  Data_buffer buffer_;
  // Socket
  Socket socket_;
};
