# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1

# Include any dependencies generated for this target.
include CMakeFiles/progTran.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/progTran.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/progTran.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/progTran.dir/flags.make

CMakeFiles/progTran.dir/progTran.cpp.o: CMakeFiles/progTran.dir/flags.make
CMakeFiles/progTran.dir/progTran.cpp.o: progTran.cpp
CMakeFiles/progTran.dir/progTran.cpp.o: CMakeFiles/progTran.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/progTran.dir/progTran.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/progTran.dir/progTran.cpp.o -MF CMakeFiles/progTran.dir/progTran.cpp.o.d -o CMakeFiles/progTran.dir/progTran.cpp.o -c /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1/progTran.cpp

CMakeFiles/progTran.dir/progTran.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progTran.dir/progTran.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1/progTran.cpp > CMakeFiles/progTran.dir/progTran.cpp.i

CMakeFiles/progTran.dir/progTran.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progTran.dir/progTran.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1/progTran.cpp -o CMakeFiles/progTran.dir/progTran.cpp.s

# Object files for target progTran
progTran_OBJECTS = \
"CMakeFiles/progTran.dir/progTran.cpp.o"

# External object files for target progTran
progTran_EXTERNAL_OBJECTS =

progTran: CMakeFiles/progTran.dir/progTran.cpp.o
progTran: CMakeFiles/progTran.dir/build.make
progTran: CMakeFiles/progTran.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable progTran"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/progTran.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/progTran.dir/build: progTran
.PHONY : CMakeFiles/progTran.dir/build

CMakeFiles/progTran.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/progTran.dir/cmake_clean.cmake
.PHONY : CMakeFiles/progTran.dir/clean

CMakeFiles/progTran.dir/depend:
	cd /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1 /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1 /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1 /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1 /home/sudakov/Documents/GeekBrains/homework/cppBase/lesson_1/CMakeFiles/progTran.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/progTran.dir/depend

