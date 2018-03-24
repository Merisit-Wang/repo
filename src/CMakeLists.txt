IF (ENABLE_TEST)
    add_subdirectory(test)
ELSE()
    FILE(GLOB_RECURSE all_files
    repo/*.cpp
    repo/*.cc
    repo/*.c++
    repo/*.c
    repo/*.C)
    
    add_executable(repo main.cpp ${all_files})
ENDIF()
