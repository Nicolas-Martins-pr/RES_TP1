cmake_minimum_required(VERSION 3.19)

set(${PROJECT_NAME}_SERVEUR_SRC   "src/server.cpp" src/terminal.cpp src/terminal.h src/network.cpp src/network.h)


add_executable(${PROJECT_NAME}_SERVEUR ${${PROJECT_NAME}_SERVEUR_SRC})
#target_link_libraries(${PROJECT_NAME}_SERVEUR PUBLIC ${PROJECT_NAME})

