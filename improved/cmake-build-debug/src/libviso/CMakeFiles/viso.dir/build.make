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
include src/libviso/CMakeFiles/viso.dir/depend.make

# Include the progress variables for this target.
include src/libviso/CMakeFiles/viso.dir/progress.make

# Include the compile flags for this target's objects.
include src/libviso/CMakeFiles/viso.dir/flags.make

src/libviso/CMakeFiles/viso.dir/triangle.cc.o: src/libviso/CMakeFiles/viso.dir/flags.make
src/libviso/CMakeFiles/viso.dir/triangle.cc.o: ../src/libviso/triangle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/libviso/CMakeFiles/viso.dir/triangle.cc.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viso.dir/triangle.cc.o -c /home/cc/workspace/repository/ignav_learning/improved/src/libviso/triangle.cc

src/libviso/CMakeFiles/viso.dir/triangle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viso.dir/triangle.cc.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/libviso/triangle.cc > CMakeFiles/viso.dir/triangle.cc.i

src/libviso/CMakeFiles/viso.dir/triangle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viso.dir/triangle.cc.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/libviso/triangle.cc -o CMakeFiles/viso.dir/triangle.cc.s

src/libviso/CMakeFiles/viso.dir/vo-filter.cc.o: src/libviso/CMakeFiles/viso.dir/flags.make
src/libviso/CMakeFiles/viso.dir/vo-filter.cc.o: ../src/libviso/vo-filter.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/libviso/CMakeFiles/viso.dir/vo-filter.cc.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viso.dir/vo-filter.cc.o -c /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-filter.cc

src/libviso/CMakeFiles/viso.dir/vo-filter.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viso.dir/vo-filter.cc.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-filter.cc > CMakeFiles/viso.dir/vo-filter.cc.i

src/libviso/CMakeFiles/viso.dir/vo-filter.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viso.dir/vo-filter.cc.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-filter.cc -o CMakeFiles/viso.dir/vo-filter.cc.s

src/libviso/CMakeFiles/viso.dir/vo-matcher.cc.o: src/libviso/CMakeFiles/viso.dir/flags.make
src/libviso/CMakeFiles/viso.dir/vo-matcher.cc.o: ../src/libviso/vo-matcher.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/libviso/CMakeFiles/viso.dir/vo-matcher.cc.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viso.dir/vo-matcher.cc.o -c /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-matcher.cc

src/libviso/CMakeFiles/viso.dir/vo-matcher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viso.dir/vo-matcher.cc.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-matcher.cc > CMakeFiles/viso.dir/vo-matcher.cc.i

src/libviso/CMakeFiles/viso.dir/vo-matcher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viso.dir/vo-matcher.cc.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-matcher.cc -o CMakeFiles/viso.dir/vo-matcher.cc.s

src/libviso/CMakeFiles/viso.dir/vo-matrix.cc.o: src/libviso/CMakeFiles/viso.dir/flags.make
src/libviso/CMakeFiles/viso.dir/vo-matrix.cc.o: ../src/libviso/vo-matrix.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/libviso/CMakeFiles/viso.dir/vo-matrix.cc.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viso.dir/vo-matrix.cc.o -c /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-matrix.cc

src/libviso/CMakeFiles/viso.dir/vo-matrix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viso.dir/vo-matrix.cc.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-matrix.cc > CMakeFiles/viso.dir/vo-matrix.cc.i

src/libviso/CMakeFiles/viso.dir/vo-matrix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viso.dir/vo-matrix.cc.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-matrix.cc -o CMakeFiles/viso.dir/vo-matrix.cc.s

src/libviso/CMakeFiles/viso.dir/vo-mono.cc.o: src/libviso/CMakeFiles/viso.dir/flags.make
src/libviso/CMakeFiles/viso.dir/vo-mono.cc.o: ../src/libviso/vo-mono.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/libviso/CMakeFiles/viso.dir/vo-mono.cc.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viso.dir/vo-mono.cc.o -c /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-mono.cc

src/libviso/CMakeFiles/viso.dir/vo-mono.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viso.dir/vo-mono.cc.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-mono.cc > CMakeFiles/viso.dir/vo-mono.cc.i

src/libviso/CMakeFiles/viso.dir/vo-mono.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viso.dir/vo-mono.cc.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-mono.cc -o CMakeFiles/viso.dir/vo-mono.cc.s

src/libviso/CMakeFiles/viso.dir/vo-stereo.cc.o: src/libviso/CMakeFiles/viso.dir/flags.make
src/libviso/CMakeFiles/viso.dir/vo-stereo.cc.o: ../src/libviso/vo-stereo.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/libviso/CMakeFiles/viso.dir/vo-stereo.cc.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viso.dir/vo-stereo.cc.o -c /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-stereo.cc

src/libviso/CMakeFiles/viso.dir/vo-stereo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viso.dir/vo-stereo.cc.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-stereo.cc > CMakeFiles/viso.dir/vo-stereo.cc.i

src/libviso/CMakeFiles/viso.dir/vo-stereo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viso.dir/vo-stereo.cc.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo-stereo.cc -o CMakeFiles/viso.dir/vo-stereo.cc.s

src/libviso/CMakeFiles/viso.dir/vo.cc.o: src/libviso/CMakeFiles/viso.dir/flags.make
src/libviso/CMakeFiles/viso.dir/vo.cc.o: ../src/libviso/vo.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/libviso/CMakeFiles/viso.dir/vo.cc.o"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viso.dir/vo.cc.o -c /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo.cc

src/libviso/CMakeFiles/viso.dir/vo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viso.dir/vo.cc.i"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo.cc > CMakeFiles/viso.dir/vo.cc.i

src/libviso/CMakeFiles/viso.dir/vo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viso.dir/vo.cc.s"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cc/workspace/repository/ignav_learning/improved/src/libviso/vo.cc -o CMakeFiles/viso.dir/vo.cc.s

# Object files for target viso
viso_OBJECTS = \
"CMakeFiles/viso.dir/triangle.cc.o" \
"CMakeFiles/viso.dir/vo-filter.cc.o" \
"CMakeFiles/viso.dir/vo-matcher.cc.o" \
"CMakeFiles/viso.dir/vo-matrix.cc.o" \
"CMakeFiles/viso.dir/vo-mono.cc.o" \
"CMakeFiles/viso.dir/vo-stereo.cc.o" \
"CMakeFiles/viso.dir/vo.cc.o"

# External object files for target viso
viso_EXTERNAL_OBJECTS =

src/libviso/libviso.a: src/libviso/CMakeFiles/viso.dir/triangle.cc.o
src/libviso/libviso.a: src/libviso/CMakeFiles/viso.dir/vo-filter.cc.o
src/libviso/libviso.a: src/libviso/CMakeFiles/viso.dir/vo-matcher.cc.o
src/libviso/libviso.a: src/libviso/CMakeFiles/viso.dir/vo-matrix.cc.o
src/libviso/libviso.a: src/libviso/CMakeFiles/viso.dir/vo-mono.cc.o
src/libviso/libviso.a: src/libviso/CMakeFiles/viso.dir/vo-stereo.cc.o
src/libviso/libviso.a: src/libviso/CMakeFiles/viso.dir/vo.cc.o
src/libviso/libviso.a: src/libviso/CMakeFiles/viso.dir/build.make
src/libviso/libviso.a: src/libviso/CMakeFiles/viso.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libviso.a"
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && $(CMAKE_COMMAND) -P CMakeFiles/viso.dir/cmake_clean_target.cmake
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/viso.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libviso/CMakeFiles/viso.dir/build: src/libviso/libviso.a

.PHONY : src/libviso/CMakeFiles/viso.dir/build

src/libviso/CMakeFiles/viso.dir/clean:
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso && $(CMAKE_COMMAND) -P CMakeFiles/viso.dir/cmake_clean.cmake
.PHONY : src/libviso/CMakeFiles/viso.dir/clean

src/libviso/CMakeFiles/viso.dir/depend:
	cd /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cc/workspace/repository/ignav_learning/improved /home/cc/workspace/repository/ignav_learning/improved/src/libviso /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso /home/cc/workspace/repository/ignav_learning/improved/cmake-build-debug/src/libviso/CMakeFiles/viso.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/libviso/CMakeFiles/viso.dir/depend

