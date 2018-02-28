project(repo)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-offsetof -g -std=c++11")

include_directories(lib/cut/include)
include_directories(repo/include)
include_directories(test/include)

add_subdirectory(lib/cut)
add_subdirectory(test)
add_subdirectory(repo)

