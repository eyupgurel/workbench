# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/egl/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/egl/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/egl/Documents/sc/C++/workbench

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/egl/Documents/sc/C++/workbench/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/workbench.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/workbench.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/workbench.dir/flags.make

CMakeFiles/workbench.dir/main.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/workbench.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/main.cpp.o -c /home/egl/Documents/sc/C++/workbench/main.cpp

CMakeFiles/workbench.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/main.cpp > CMakeFiles/workbench.dir/main.cpp.i

CMakeFiles/workbench.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/main.cpp -o CMakeFiles/workbench.dir/main.cpp.s

CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.o: ../algorithms/hanoitower.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.o -c /home/egl/Documents/sc/C++/workbench/algorithms/hanoitower.cpp

CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/algorithms/hanoitower.cpp > CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.i

CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/algorithms/hanoitower.cpp -o CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.s

CMakeFiles/workbench.dir/algorithms/mergesort.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/algorithms/mergesort.cpp.o: ../algorithms/mergesort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/workbench.dir/algorithms/mergesort.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/algorithms/mergesort.cpp.o -c /home/egl/Documents/sc/C++/workbench/algorithms/mergesort.cpp

CMakeFiles/workbench.dir/algorithms/mergesort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/algorithms/mergesort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/algorithms/mergesort.cpp > CMakeFiles/workbench.dir/algorithms/mergesort.cpp.i

CMakeFiles/workbench.dir/algorithms/mergesort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/algorithms/mergesort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/algorithms/mergesort.cpp -o CMakeFiles/workbench.dir/algorithms/mergesort.cpp.s

CMakeFiles/workbench.dir/containers/vector.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/containers/vector.cpp.o: ../containers/vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/workbench.dir/containers/vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/containers/vector.cpp.o -c /home/egl/Documents/sc/C++/workbench/containers/vector.cpp

CMakeFiles/workbench.dir/containers/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/containers/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/containers/vector.cpp > CMakeFiles/workbench.dir/containers/vector.cpp.i

CMakeFiles/workbench.dir/containers/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/containers/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/containers/vector.cpp -o CMakeFiles/workbench.dir/containers/vector.cpp.s

CMakeFiles/workbench.dir/containers/vector_container.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/containers/vector_container.cpp.o: ../containers/vector_container.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/workbench.dir/containers/vector_container.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/containers/vector_container.cpp.o -c /home/egl/Documents/sc/C++/workbench/containers/vector_container.cpp

CMakeFiles/workbench.dir/containers/vector_container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/containers/vector_container.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/containers/vector_container.cpp > CMakeFiles/workbench.dir/containers/vector_container.cpp.i

CMakeFiles/workbench.dir/containers/vector_container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/containers/vector_container.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/containers/vector_container.cpp -o CMakeFiles/workbench.dir/containers/vector_container.cpp.s

CMakeFiles/workbench.dir/containers/list_container.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/containers/list_container.cpp.o: ../containers/list_container.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/workbench.dir/containers/list_container.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/containers/list_container.cpp.o -c /home/egl/Documents/sc/C++/workbench/containers/list_container.cpp

CMakeFiles/workbench.dir/containers/list_container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/containers/list_container.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/containers/list_container.cpp > CMakeFiles/workbench.dir/containers/list_container.cpp.i

CMakeFiles/workbench.dir/containers/list_container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/containers/list_container.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/containers/list_container.cpp -o CMakeFiles/workbench.dir/containers/list_container.cpp.s

CMakeFiles/workbench.dir/containers/myarray.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/containers/myarray.cpp.o: ../containers/myarray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/workbench.dir/containers/myarray.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/containers/myarray.cpp.o -c /home/egl/Documents/sc/C++/workbench/containers/myarray.cpp

CMakeFiles/workbench.dir/containers/myarray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/containers/myarray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/containers/myarray.cpp > CMakeFiles/workbench.dir/containers/myarray.cpp.i

CMakeFiles/workbench.dir/containers/myarray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/containers/myarray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/containers/myarray.cpp -o CMakeFiles/workbench.dir/containers/myarray.cpp.s

CMakeFiles/workbench.dir/union/Entry.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/union/Entry.cpp.o: ../union/Entry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/workbench.dir/union/Entry.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/union/Entry.cpp.o -c /home/egl/Documents/sc/C++/workbench/union/Entry.cpp

CMakeFiles/workbench.dir/union/Entry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/union/Entry.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/union/Entry.cpp > CMakeFiles/workbench.dir/union/Entry.cpp.i

CMakeFiles/workbench.dir/union/Entry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/union/Entry.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/union/Entry.cpp -o CMakeFiles/workbench.dir/union/Entry.cpp.s

CMakeFiles/workbench.dir/algorithms/shellsort.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/algorithms/shellsort.cpp.o: ../algorithms/shellsort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/workbench.dir/algorithms/shellsort.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/algorithms/shellsort.cpp.o -c /home/egl/Documents/sc/C++/workbench/algorithms/shellsort.cpp

CMakeFiles/workbench.dir/algorithms/shellsort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/algorithms/shellsort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/algorithms/shellsort.cpp > CMakeFiles/workbench.dir/algorithms/shellsort.cpp.i

CMakeFiles/workbench.dir/algorithms/shellsort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/algorithms/shellsort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/algorithms/shellsort.cpp -o CMakeFiles/workbench.dir/algorithms/shellsort.cpp.s

CMakeFiles/workbench.dir/assert/assert.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/assert/assert.cpp.o: ../assert/assert.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/workbench.dir/assert/assert.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/assert/assert.cpp.o -c /home/egl/Documents/sc/C++/workbench/assert/assert.cpp

CMakeFiles/workbench.dir/assert/assert.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/assert/assert.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/assert/assert.cpp > CMakeFiles/workbench.dir/assert/assert.cpp.i

CMakeFiles/workbench.dir/assert/assert.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/assert/assert.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/assert/assert.cpp -o CMakeFiles/workbench.dir/assert/assert.cpp.s

CMakeFiles/workbench.dir/containers/vectorex.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/containers/vectorex.cpp.o: ../containers/vectorex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/workbench.dir/containers/vectorex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/containers/vectorex.cpp.o -c /home/egl/Documents/sc/C++/workbench/containers/vectorex.cpp

CMakeFiles/workbench.dir/containers/vectorex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/containers/vectorex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/containers/vectorex.cpp > CMakeFiles/workbench.dir/containers/vectorex.cpp.i

CMakeFiles/workbench.dir/containers/vectorex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/containers/vectorex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/containers/vectorex.cpp -o CMakeFiles/workbench.dir/containers/vectorex.cpp.s

CMakeFiles/workbench.dir/containers/vector_base.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/containers/vector_base.cpp.o: ../containers/vector_base.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/workbench.dir/containers/vector_base.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/containers/vector_base.cpp.o -c /home/egl/Documents/sc/C++/workbench/containers/vector_base.cpp

CMakeFiles/workbench.dir/containers/vector_base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/containers/vector_base.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/containers/vector_base.cpp > CMakeFiles/workbench.dir/containers/vector_base.cpp.i

CMakeFiles/workbench.dir/containers/vector_base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/containers/vector_base.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/containers/vector_base.cpp -o CMakeFiles/workbench.dir/containers/vector_base.cpp.s

CMakeFiles/workbench.dir/chrono/chrono.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/chrono/chrono.cpp.o: ../chrono/chrono.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/workbench.dir/chrono/chrono.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/chrono/chrono.cpp.o -c /home/egl/Documents/sc/C++/workbench/chrono/chrono.cpp

CMakeFiles/workbench.dir/chrono/chrono.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/chrono/chrono.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/chrono/chrono.cpp > CMakeFiles/workbench.dir/chrono/chrono.cpp.i

CMakeFiles/workbench.dir/chrono/chrono.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/chrono/chrono.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/chrono/chrono.cpp -o CMakeFiles/workbench.dir/chrono/chrono.cpp.s

CMakeFiles/workbench.dir/lifetime/lifetime.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/lifetime/lifetime.cpp.o: ../lifetime/lifetime.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/workbench.dir/lifetime/lifetime.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/lifetime/lifetime.cpp.o -c /home/egl/Documents/sc/C++/workbench/lifetime/lifetime.cpp

CMakeFiles/workbench.dir/lifetime/lifetime.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/lifetime/lifetime.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/lifetime/lifetime.cpp > CMakeFiles/workbench.dir/lifetime/lifetime.cpp.i

CMakeFiles/workbench.dir/lifetime/lifetime.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/lifetime/lifetime.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/lifetime/lifetime.cpp -o CMakeFiles/workbench.dir/lifetime/lifetime.cpp.s

CMakeFiles/workbench.dir/containers/simplematrix.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/containers/simplematrix.cpp.o: ../containers/simplematrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/workbench.dir/containers/simplematrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/containers/simplematrix.cpp.o -c /home/egl/Documents/sc/C++/workbench/containers/simplematrix.cpp

CMakeFiles/workbench.dir/containers/simplematrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/containers/simplematrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/containers/simplematrix.cpp > CMakeFiles/workbench.dir/containers/simplematrix.cpp.i

CMakeFiles/workbench.dir/containers/simplematrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/containers/simplematrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/containers/simplematrix.cpp -o CMakeFiles/workbench.dir/containers/simplematrix.cpp.s

CMakeFiles/workbench.dir/forward/forward.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/forward/forward.cpp.o: ../forward/forward.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/workbench.dir/forward/forward.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/forward/forward.cpp.o -c /home/egl/Documents/sc/C++/workbench/forward/forward.cpp

CMakeFiles/workbench.dir/forward/forward.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/forward/forward.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/forward/forward.cpp > CMakeFiles/workbench.dir/forward/forward.cpp.i

CMakeFiles/workbench.dir/forward/forward.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/forward/forward.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/forward/forward.cpp -o CMakeFiles/workbench.dir/forward/forward.cpp.s

CMakeFiles/workbench.dir/forward/Xref.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/forward/Xref.cpp.o: ../forward/Xref.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/workbench.dir/forward/Xref.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/forward/Xref.cpp.o -c /home/egl/Documents/sc/C++/workbench/forward/Xref.cpp

CMakeFiles/workbench.dir/forward/Xref.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/forward/Xref.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/forward/Xref.cpp > CMakeFiles/workbench.dir/forward/Xref.cpp.i

CMakeFiles/workbench.dir/forward/Xref.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/forward/Xref.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/forward/Xref.cpp -o CMakeFiles/workbench.dir/forward/Xref.cpp.s

CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.o: ../SFINAE/SFINAE.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.o -c /home/egl/Documents/sc/C++/workbench/SFINAE/SFINAE.cpp

CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/SFINAE/SFINAE.cpp > CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.i

CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/SFINAE/SFINAE.cpp -o CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.s

CMakeFiles/workbench.dir/templates/array/array.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/templates/array/array.cpp.o: ../templates/array/array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/workbench.dir/templates/array/array.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/templates/array/array.cpp.o -c /home/egl/Documents/sc/C++/workbench/templates/array/array.cpp

CMakeFiles/workbench.dir/templates/array/array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/templates/array/array.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/templates/array/array.cpp > CMakeFiles/workbench.dir/templates/array/array.cpp.i

CMakeFiles/workbench.dir/templates/array/array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/templates/array/array.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/templates/array/array.cpp -o CMakeFiles/workbench.dir/templates/array/array.cpp.s

CMakeFiles/workbench.dir/math/_complex.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/math/_complex.cpp.o: ../math/_complex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/workbench.dir/math/_complex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/math/_complex.cpp.o -c /home/egl/Documents/sc/C++/workbench/math/_complex.cpp

CMakeFiles/workbench.dir/math/_complex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/math/_complex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/math/_complex.cpp > CMakeFiles/workbench.dir/math/_complex.cpp.i

CMakeFiles/workbench.dir/math/_complex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/math/_complex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/math/_complex.cpp -o CMakeFiles/workbench.dir/math/_complex.cpp.s

CMakeFiles/workbench.dir/typeconversion/tiny.cpp.o: CMakeFiles/workbench.dir/flags.make
CMakeFiles/workbench.dir/typeconversion/tiny.cpp.o: ../typeconversion/tiny.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/workbench.dir/typeconversion/tiny.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workbench.dir/typeconversion/tiny.cpp.o -c /home/egl/Documents/sc/C++/workbench/typeconversion/tiny.cpp

CMakeFiles/workbench.dir/typeconversion/tiny.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workbench.dir/typeconversion/tiny.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egl/Documents/sc/C++/workbench/typeconversion/tiny.cpp > CMakeFiles/workbench.dir/typeconversion/tiny.cpp.i

CMakeFiles/workbench.dir/typeconversion/tiny.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workbench.dir/typeconversion/tiny.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egl/Documents/sc/C++/workbench/typeconversion/tiny.cpp -o CMakeFiles/workbench.dir/typeconversion/tiny.cpp.s

# Object files for target workbench
workbench_OBJECTS = \
"CMakeFiles/workbench.dir/main.cpp.o" \
"CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.o" \
"CMakeFiles/workbench.dir/algorithms/mergesort.cpp.o" \
"CMakeFiles/workbench.dir/containers/vector.cpp.o" \
"CMakeFiles/workbench.dir/containers/vector_container.cpp.o" \
"CMakeFiles/workbench.dir/containers/list_container.cpp.o" \
"CMakeFiles/workbench.dir/containers/myarray.cpp.o" \
"CMakeFiles/workbench.dir/union/Entry.cpp.o" \
"CMakeFiles/workbench.dir/algorithms/shellsort.cpp.o" \
"CMakeFiles/workbench.dir/assert/assert.cpp.o" \
"CMakeFiles/workbench.dir/containers/vectorex.cpp.o" \
"CMakeFiles/workbench.dir/containers/vector_base.cpp.o" \
"CMakeFiles/workbench.dir/chrono/chrono.cpp.o" \
"CMakeFiles/workbench.dir/lifetime/lifetime.cpp.o" \
"CMakeFiles/workbench.dir/containers/simplematrix.cpp.o" \
"CMakeFiles/workbench.dir/forward/forward.cpp.o" \
"CMakeFiles/workbench.dir/forward/Xref.cpp.o" \
"CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.o" \
"CMakeFiles/workbench.dir/templates/array/array.cpp.o" \
"CMakeFiles/workbench.dir/math/_complex.cpp.o" \
"CMakeFiles/workbench.dir/typeconversion/tiny.cpp.o"

# External object files for target workbench
workbench_EXTERNAL_OBJECTS =

workbench: CMakeFiles/workbench.dir/main.cpp.o
workbench: CMakeFiles/workbench.dir/algorithms/hanoitower.cpp.o
workbench: CMakeFiles/workbench.dir/algorithms/mergesort.cpp.o
workbench: CMakeFiles/workbench.dir/containers/vector.cpp.o
workbench: CMakeFiles/workbench.dir/containers/vector_container.cpp.o
workbench: CMakeFiles/workbench.dir/containers/list_container.cpp.o
workbench: CMakeFiles/workbench.dir/containers/myarray.cpp.o
workbench: CMakeFiles/workbench.dir/union/Entry.cpp.o
workbench: CMakeFiles/workbench.dir/algorithms/shellsort.cpp.o
workbench: CMakeFiles/workbench.dir/assert/assert.cpp.o
workbench: CMakeFiles/workbench.dir/containers/vectorex.cpp.o
workbench: CMakeFiles/workbench.dir/containers/vector_base.cpp.o
workbench: CMakeFiles/workbench.dir/chrono/chrono.cpp.o
workbench: CMakeFiles/workbench.dir/lifetime/lifetime.cpp.o
workbench: CMakeFiles/workbench.dir/containers/simplematrix.cpp.o
workbench: CMakeFiles/workbench.dir/forward/forward.cpp.o
workbench: CMakeFiles/workbench.dir/forward/Xref.cpp.o
workbench: CMakeFiles/workbench.dir/SFINAE/SFINAE.cpp.o
workbench: CMakeFiles/workbench.dir/templates/array/array.cpp.o
workbench: CMakeFiles/workbench.dir/math/_complex.cpp.o
workbench: CMakeFiles/workbench.dir/typeconversion/tiny.cpp.o
workbench: CMakeFiles/workbench.dir/build.make
workbench: CMakeFiles/workbench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Linking CXX executable workbench"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/workbench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/workbench.dir/build: workbench

.PHONY : CMakeFiles/workbench.dir/build

CMakeFiles/workbench.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/workbench.dir/cmake_clean.cmake
.PHONY : CMakeFiles/workbench.dir/clean

CMakeFiles/workbench.dir/depend:
	cd /home/egl/Documents/sc/C++/workbench/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/egl/Documents/sc/C++/workbench /home/egl/Documents/sc/C++/workbench /home/egl/Documents/sc/C++/workbench/cmake-build-debug /home/egl/Documents/sc/C++/workbench/cmake-build-debug /home/egl/Documents/sc/C++/workbench/cmake-build-debug/CMakeFiles/workbench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/workbench.dir/depend

