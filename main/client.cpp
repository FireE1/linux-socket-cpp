#include "../src/client/core.h"

int main(int argc, char *argv[]) {
  Client client;
  std::thread reader(&Client::ReaderLoop, &client);
  std::thread sender(&Client::SenderLoop, &client);
  reader.join();
  sender.join();

  return 0;
}
