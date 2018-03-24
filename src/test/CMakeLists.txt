project(repo-test)

FILE(GLOB_RECURSE all_files
*.cpp
../repo/*.cpp
*.cc
*.c++
*.c
*.C)

add_executable(repo-test ${all_files})
target_link_libraries(repo-test cut)
