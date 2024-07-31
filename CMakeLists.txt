cmake_minimum_required(VERSION 3.12)

project(Infotecs_test)
set(CMAKE_CXX_STANDART 17)

find_package(Threads REQUIRED)

set(CLIENT_SRC  ./src/client/core.h
                ./src/client/core.cpp
                ./src/client/socket.h
                ./src/client/socket.cpp
                ./src/client/data_buffer.h
                ./src/client/data_buffer.cpp)

set(SERVER_SRC  ./src/server/core.h
                ./src/server/core.cpp)

add_executable(client ./main/client.cpp ${CLIENT_SRC})
add_executable(server ./main/server.cpp ${SERVER_SRC})

target_include_directories(client PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(client Threads::Threads)

target_include_directories(server PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

