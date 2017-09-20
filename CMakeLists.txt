cmake_minimum_required(VERSION 3.5.1)
project(hw1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/Media.h include/Shapes.h include/Sort.h Sort.cpp Shapes.cpp utSort.h)
add_executable(hw1 ${SOURCE_FILES})


## for google test
enable_testing()
add_subdirectory(googletest)
include_directories(googletest/include googletest)
target_link_libraries(hw1 gtest gtest_main)

