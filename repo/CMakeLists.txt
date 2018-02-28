FILE(GLOB_RECURSE all_files
*.cpp
*.cc
*.c++
*.c
*.C)

include_directories(include)
add_library(repo STATIC ${all_files})