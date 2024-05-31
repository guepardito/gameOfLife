cmake_minimum_required(VERSION 3.20)

project(gameOfLife CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(includes)

file(GLOB SOURCES "src/*.cpp")

add_executable(gameOfLife ${SOURCES})

find_package(SFML COMPONENTS system window graphics REQUIRED)
target_link_libraries(gameOfLife sfml-system sfml-window sfml-graphics) 