cmake_minimum_required(VERSION 3.20)
project(dasr_second_second)

set(CMAKE_CXX_STANDARD 20)

add_executable(dasr_second_second main.cpp)

add_executable(vehicles vehicles.cpp)
add_executable(polyline polyline.cpp)
add_executable(rational rational.cpp)
