# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stesta/Desktop/UBA/AYP2/TP1/test_template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stesta/Desktop/UBA/AYP2/TP1/test_template

# Include any dependencies generated for this target.
include CMakeFiles/Google_Tests_run.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Google_Tests_run.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Google_Tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Google_Tests_run.dir/flags.make

CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.o: CMakeFiles/Google_Tests_run.dir/flags.make
CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.o: VectorTemplateTests.cpp
CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.o: CMakeFiles/Google_Tests_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stesta/Desktop/UBA/AYP2/TP1/test_template/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.o -MF CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.o.d -o CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.o -c /home/stesta/Desktop/UBA/AYP2/TP1/test_template/VectorTemplateTests.cpp

CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stesta/Desktop/UBA/AYP2/TP1/test_template/VectorTemplateTests.cpp > CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.i

CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stesta/Desktop/UBA/AYP2/TP1/test_template/VectorTemplateTests.cpp -o CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.s

# Object files for target Google_Tests_run
Google_Tests_run_OBJECTS = \
"CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.o"

# External object files for target Google_Tests_run
Google_Tests_run_EXTERNAL_OBJECTS =

Google_Tests_run: CMakeFiles/Google_Tests_run.dir/VectorTemplateTests.cpp.o
Google_Tests_run: CMakeFiles/Google_Tests_run.dir/build.make
Google_Tests_run: lib/libgtest.a
Google_Tests_run: lib/libgtest_main.a
Google_Tests_run: lib/libgtest.a
Google_Tests_run: CMakeFiles/Google_Tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stesta/Desktop/UBA/AYP2/TP1/test_template/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Google_Tests_run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Google_Tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Google_Tests_run.dir/build: Google_Tests_run
.PHONY : CMakeFiles/Google_Tests_run.dir/build

CMakeFiles/Google_Tests_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Google_Tests_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Google_Tests_run.dir/clean

CMakeFiles/Google_Tests_run.dir/depend:
	cd /home/stesta/Desktop/UBA/AYP2/TP1/test_template && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stesta/Desktop/UBA/AYP2/TP1/test_template /home/stesta/Desktop/UBA/AYP2/TP1/test_template /home/stesta/Desktop/UBA/AYP2/TP1/test_template /home/stesta/Desktop/UBA/AYP2/TP1/test_template /home/stesta/Desktop/UBA/AYP2/TP1/test_template/CMakeFiles/Google_Tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Google_Tests_run.dir/depend
