# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/cc/software/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/cc/software/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cc/workspace/repository/ignav_learning/improved

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug

# Include any dependencies generated for this target.
include src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/depend.make

# Include the progress variables for this target.
include src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/progress.make

# Include the compile flags for this target's objects.
include src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/flags.make

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.o: src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/flags.make
src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.o: ../src/relative-pose/seven-eight-point/seven-eight-point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.o -c /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point/seven-eight-point.cpp

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point/seven-eight-point.cpp > CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.i

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point/seven-eight-point.cpp -o CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.s

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/precomp.cpp.o: src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/flags.make
src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/precomp.cpp.o: ../src/relative-pose/seven-eight-point/precomp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/precomp.cpp.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seven-eight-point.dir/precomp.cpp.o -c /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point/precomp.cpp

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/precomp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seven-eight-point.dir/precomp.cpp.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point/precomp.cpp > CMakeFiles/seven-eight-point.dir/precomp.cpp.i

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/precomp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seven-eight-point.dir/precomp.cpp.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point/precomp.cpp -o CMakeFiles/seven-eight-point.dir/precomp.cpp.s

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/modelest.cpp.o: src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/flags.make
src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/modelest.cpp.o: ../src/relative-pose/seven-eight-point/modelest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/modelest.cpp.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seven-eight-point.dir/modelest.cpp.o -c /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point/modelest.cpp

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/modelest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seven-eight-point.dir/modelest.cpp.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point/modelest.cpp > CMakeFiles/seven-eight-point.dir/modelest.cpp.i

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/modelest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seven-eight-point.dir/modelest.cpp.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point/modelest.cpp -o CMakeFiles/seven-eight-point.dir/modelest.cpp.s

# Object files for target seven-eight-point
seven__eight__point_OBJECTS = \
"CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.o" \
"CMakeFiles/seven-eight-point.dir/precomp.cpp.o" \
"CMakeFiles/seven-eight-point.dir/modelest.cpp.o"

# External object files for target seven-eight-point
seven__eight__point_EXTERNAL_OBJECTS =

src/relative-pose/seven-eight-point/libseven-eight-point.a: src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/seven-eight-point.cpp.o
src/relative-pose/seven-eight-point/libseven-eight-point.a: src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/precomp.cpp.o
src/relative-pose/seven-eight-point/libseven-eight-point.a: src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/modelest.cpp.o
src/relative-pose/seven-eight-point/libseven-eight-point.a: src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/build.make
src/relative-pose/seven-eight-point/libseven-eight-point.a: src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libseven-eight-point.a"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && $(CMAKE_COMMAND) -P CMakeFiles/seven-eight-point.dir/cmake_clean_target.cmake
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/seven-eight-point.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/build: src/relative-pose/seven-eight-point/libseven-eight-point.a

.PHONY : src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/build

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/clean:
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point && $(CMAKE_COMMAND) -P CMakeFiles/seven-eight-point.dir/cmake_clean.cmake
.PHONY : src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/clean

src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/depend:
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cc/workspace/repository/ignav_learning/improved /home/cc/workspace/repository/ignav_learning/improved/src/relative-pose/seven-eight-point /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/relative-pose/seven-eight-point/CMakeFiles/seven-eight-point.dir/depend

