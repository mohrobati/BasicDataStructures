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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zosoist/CLionProjects/QueueWithLinkedList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zosoist/CLionProjects/QueueWithLinkedList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/QueueWithLinkedList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QueueWithLinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QueueWithLinkedList.dir/flags.make

CMakeFiles/QueueWithLinkedList.dir/main.c.o: CMakeFiles/QueueWithLinkedList.dir/flags.make
CMakeFiles/QueueWithLinkedList.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zosoist/CLionProjects/QueueWithLinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/QueueWithLinkedList.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/QueueWithLinkedList.dir/main.c.o   -c /Users/zosoist/CLionProjects/QueueWithLinkedList/main.c

CMakeFiles/QueueWithLinkedList.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/QueueWithLinkedList.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zosoist/CLionProjects/QueueWithLinkedList/main.c > CMakeFiles/QueueWithLinkedList.dir/main.c.i

CMakeFiles/QueueWithLinkedList.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/QueueWithLinkedList.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zosoist/CLionProjects/QueueWithLinkedList/main.c -o CMakeFiles/QueueWithLinkedList.dir/main.c.s

CMakeFiles/QueueWithLinkedList.dir/main.c.o.requires:

.PHONY : CMakeFiles/QueueWithLinkedList.dir/main.c.o.requires

CMakeFiles/QueueWithLinkedList.dir/main.c.o.provides: CMakeFiles/QueueWithLinkedList.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/QueueWithLinkedList.dir/build.make CMakeFiles/QueueWithLinkedList.dir/main.c.o.provides.build
.PHONY : CMakeFiles/QueueWithLinkedList.dir/main.c.o.provides

CMakeFiles/QueueWithLinkedList.dir/main.c.o.provides.build: CMakeFiles/QueueWithLinkedList.dir/main.c.o


# Object files for target QueueWithLinkedList
QueueWithLinkedList_OBJECTS = \
"CMakeFiles/QueueWithLinkedList.dir/main.c.o"

# External object files for target QueueWithLinkedList
QueueWithLinkedList_EXTERNAL_OBJECTS =

QueueWithLinkedList: CMakeFiles/QueueWithLinkedList.dir/main.c.o
QueueWithLinkedList: CMakeFiles/QueueWithLinkedList.dir/build.make
QueueWithLinkedList: CMakeFiles/QueueWithLinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zosoist/CLionProjects/QueueWithLinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable QueueWithLinkedList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QueueWithLinkedList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QueueWithLinkedList.dir/build: QueueWithLinkedList

.PHONY : CMakeFiles/QueueWithLinkedList.dir/build

CMakeFiles/QueueWithLinkedList.dir/requires: CMakeFiles/QueueWithLinkedList.dir/main.c.o.requires

.PHONY : CMakeFiles/QueueWithLinkedList.dir/requires

CMakeFiles/QueueWithLinkedList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QueueWithLinkedList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QueueWithLinkedList.dir/clean

CMakeFiles/QueueWithLinkedList.dir/depend:
	cd /Users/zosoist/CLionProjects/QueueWithLinkedList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zosoist/CLionProjects/QueueWithLinkedList /Users/zosoist/CLionProjects/QueueWithLinkedList /Users/zosoist/CLionProjects/QueueWithLinkedList/cmake-build-debug /Users/zosoist/CLionProjects/QueueWithLinkedList/cmake-build-debug /Users/zosoist/CLionProjects/QueueWithLinkedList/cmake-build-debug/CMakeFiles/QueueWithLinkedList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QueueWithLinkedList.dir/depend

