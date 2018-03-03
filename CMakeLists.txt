project(repo)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-offsetof -g -std=c++11")

include_directories(include/repo)
include_directories(include/test)
include_directories(tools/cut/include)

add_subdirectory(tools/cut)
add_subdirectory(src)
