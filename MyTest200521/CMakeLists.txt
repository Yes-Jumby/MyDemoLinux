# Copyright 2016 SICK AG. All rights reserved.
# Build definitions for Ranger GenICam helper library
project(MyTest)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)

# List all sources files
set(PUBLIC_SOURCE
    MyTest.cpp)

source_group("public" FILES ${PUBLIC_SOURCE})

set(EXECUTABLE_FILE_NAME "${PROJECT_NAME}${BUILD_TYPE_EXTENSION}")
# Create a executable
add_executable(${EXECUTABLE_FILE_NAME} ${PUBLIC_SOURCE})