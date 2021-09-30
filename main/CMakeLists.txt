cmake_minimum_required(VERSION 3.19)

set(ProjectExample_Version ${Version})

set(${PROJECT_NAME}_SRC 
                        "src/object.cpp"
                        "src/world.cpp")

set(${PROJECT_NAME}_HEADERS "include/ProjectExample/object.hpp"
                            "include/ProjectExample/world.hpp")

add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC include)