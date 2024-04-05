cmake_minimum_required(VERSION 3.10)

project(PingPong VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(raylib/include)

add_executable(PingPong Main.cpp Object.cpp)

target_link_libraries(PingPong raylib/lib/raylibdll)
