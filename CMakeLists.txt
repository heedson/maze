cmake_minimum_required(VERSION 3.5)

project(maze)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

add_executable(main main.cpp)

target_link_libraries(main ${SFML_LIBRARIES})