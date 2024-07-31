# linux-socket-cpp
Simple client-server program that uses linux socket.

## How this works:
Client will wait for input, that must contain only digits(client parse). All even digits will be replaced and all odd digits would be accumilated and result sended to server. Server recieve message and will check it for length(>= 2) and if its multiple by 32.

## Usage:
- Start client.
- Start server.
- Input string with only digits in to client.
- Server will respond with number if all for client input requirements are passed. Otherwise it will give error.

## Build requirements:
- C++17 (STL)
- CMake 3.12+
