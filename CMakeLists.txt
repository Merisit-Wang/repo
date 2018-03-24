project(repo)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-offsetof -g -std=c++11")

include_directories(include/repo)
include_directories(include/test)
include_directories(tools/cut/include)

OPTION(ENABLE_TEST "Build repo test." OFF)

add_subdirectory(src)

IF (ENABLE_TEST)
    add_subdirectory(tools/cut)
ENDIF()