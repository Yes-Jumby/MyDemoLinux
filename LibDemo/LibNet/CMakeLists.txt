cmake_minimum_required(VERSION 3.7)
project(Static_Lib_EXE)
 
set(CMAKE_CXX_STANDARD 11)

add_library(StaticBubble SHARED StaticBubble.cpp)   #STATIC  or SHARED

include_directories(${PROJECT_SOURCE_DIR})
add_executable(Static_Lib_EXE testBubble.cpp)
target_link_libraries(Static_Lib_EXE StaticBubble)