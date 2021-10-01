cmake_minimum_required(VERSION 3.19)

set(${PROJECT_NAME}_CLIENT_SRC   "src/client.cpp")


add_executable(${PROJECT_NAME}_CLIENT ${${PROJECT_NAME}_CLIENT_SRC})
#target_link_libraries(${PROJECT_NAME}_CLIENT PUBLIC ${PROJECT_NAME})