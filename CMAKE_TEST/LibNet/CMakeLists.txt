cmake_minimum_required(VERSION 3.7)
project(Static_Lib_EXE)
 
set(CMAKE_CXX_STANDARD 11)


#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../Bin)       #设置可执行文件的输出目录
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../Lib)           #设置库文件的输出目录
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../Lib)           #设置库文件的输出目录

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../Bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../Bin/Release)

#上面两条语句分别设置了Debug版本和Release版本可执行文件的输出目录,

#一旦设置上面的属性,在任何环境下生成的可执行文件都将直接放在你所设置的目录.

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../Lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../Lib/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../Lib/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../Lib/Release)
#上面两条语句分别设置了Debug版本和Release版本库文件的输出目录,


add_library(StaticBubble STATIC StaticBubble.cpp)   #STATIC  or SHARED

include_directories(${PROJECT_SOURCE_DIR})
add_executable(Static_Lib_EXE testBubble.cpp)
target_link_libraries(Static_Lib_EXE StaticBubble)
