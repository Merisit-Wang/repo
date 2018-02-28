FILE(GLOB_RECURSE all_files
*.cpp
*.cc
*.c++
*.c
*.C)

add_executable(repo-test ${all_files})
target_link_libraries(repo-test repo cut)