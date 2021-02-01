cmake_minimum_required(VERSION 3.17)
project(myshell)

set(CMAKE_CXX_STANDARD 20)

set(SERVER_SOURCES src/Server.cpp src/Shell.cpp) # add source files here

include_directories(inc)

add_executable(${CMAKE_PROJECT_NAME} server.cpp ${SERVER_SOURCES})
