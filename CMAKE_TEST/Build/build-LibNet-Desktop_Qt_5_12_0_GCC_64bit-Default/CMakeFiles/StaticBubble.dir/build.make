# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/LibNet"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/Build/build-LibNet-Desktop_Qt_5_12_0_GCC_64bit-Default"

# Include any dependencies generated for this target.
include CMakeFiles/StaticBubble.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StaticBubble.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StaticBubble.dir/flags.make

CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o: CMakeFiles/StaticBubble.dir/flags.make
CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o: /home/ubuntu/Documents/work/my\ first\ project/CMAKE_TEST/LibNet/StaticBubble.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Documents/work/my first project/CMAKE_TEST/Build/build-LibNet-Desktop_Qt_5_12_0_GCC_64bit-Default/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o -c "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/LibNet/StaticBubble.cpp"

CMakeFiles/StaticBubble.dir/StaticBubble.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StaticBubble.dir/StaticBubble.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/LibNet/StaticBubble.cpp" > CMakeFiles/StaticBubble.dir/StaticBubble.cpp.i

CMakeFiles/StaticBubble.dir/StaticBubble.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StaticBubble.dir/StaticBubble.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/LibNet/StaticBubble.cpp" -o CMakeFiles/StaticBubble.dir/StaticBubble.cpp.s

CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o.requires:

.PHONY : CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o.requires

CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o.provides: CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o.requires
	$(MAKE) -f CMakeFiles/StaticBubble.dir/build.make CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o.provides.build
.PHONY : CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o.provides

CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o.provides.build: CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o


# Object files for target StaticBubble
StaticBubble_OBJECTS = \
"CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o"

# External object files for target StaticBubble
StaticBubble_EXTERNAL_OBJECTS =

/home/ubuntu/Documents/work/my\ first\ project/CMAKE_TEST/Lib/libStaticBubble.so: CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o
/home/ubuntu/Documents/work/my\ first\ project/CMAKE_TEST/Lib/libStaticBubble.so: CMakeFiles/StaticBubble.dir/build.make
/home/ubuntu/Documents/work/my\ first\ project/CMAKE_TEST/Lib/libStaticBubble.so: CMakeFiles/StaticBubble.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ubuntu/Documents/work/my first project/CMAKE_TEST/Build/build-LibNet-Desktop_Qt_5_12_0_GCC_64bit-Default/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library \"/home/ubuntu/Documents/work/my first project/CMAKE_TEST/Lib/libStaticBubble.so\""
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StaticBubble.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StaticBubble.dir/build: /home/ubuntu/Documents/work/my\ first\ project/CMAKE_TEST/Lib/libStaticBubble.so

.PHONY : CMakeFiles/StaticBubble.dir/build

CMakeFiles/StaticBubble.dir/requires: CMakeFiles/StaticBubble.dir/StaticBubble.cpp.o.requires

.PHONY : CMakeFiles/StaticBubble.dir/requires

CMakeFiles/StaticBubble.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StaticBubble.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StaticBubble.dir/clean

CMakeFiles/StaticBubble.dir/depend:
	cd "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/Build/build-LibNet-Desktop_Qt_5_12_0_GCC_64bit-Default" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/LibNet" "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/LibNet" "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/Build/build-LibNet-Desktop_Qt_5_12_0_GCC_64bit-Default" "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/Build/build-LibNet-Desktop_Qt_5_12_0_GCC_64bit-Default" "/home/ubuntu/Documents/work/my first project/CMAKE_TEST/Build/build-LibNet-Desktop_Qt_5_12_0_GCC_64bit-Default/CMakeFiles/StaticBubble.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/StaticBubble.dir/depend
