cmake_minimum_required(VERSION 3.19)

project(Project VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

#option(SERVER_BUILD "server build" ON)
#option(CLIENT_BUILD "client build" ON)

add_subdirectory(ServerApplication)
add_subdirectory(ClientApplication)