cmake_minimum_required(VERSION 3.19)

set(${PROJECT_NAME}_SERVEUR_SRC   src/server.cpp src/connection.cpp src/connection.h src/UDPConnection.cpp src/UDPConnection.h src/TCPConnection.cpp src/TCPConnection.h src/network.h src/network.cpp src/terminal.h src/terminal.cpp)


add_executable(${PROJECT_NAME}_SERVEUR ${${PROJECT_NAME}_SERVEUR_SRC})
#target_link_libraries(${PROJECT_NAME}_SERVEUR PUBLIC ${PROJECT_NAME})

