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
CMAKE_SOURCE_DIR = /Users/zosoist/CLionProjects/SinglyLinkedList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zosoist/CLionProjects/SinglyLinkedList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SinglyLinkedList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SinglyLinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SinglyLinkedList.dir/flags.make

CMakeFiles/SinglyLinkedList.dir/main.c.o: CMakeFiles/SinglyLinkedList.dir/flags.make
CMakeFiles/SinglyLinkedList.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zosoist/CLionProjects/SinglyLinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SinglyLinkedList.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SinglyLinkedList.dir/main.c.o   -c /Users/zosoist/CLionProjects/SinglyLinkedList/main.c

CMakeFiles/SinglyLinkedList.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SinglyLinkedList.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zosoist/CLionProjects/SinglyLinkedList/main.c > CMakeFiles/SinglyLinkedList.dir/main.c.i

CMakeFiles/SinglyLinkedList.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SinglyLinkedList.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zosoist/CLionProjects/SinglyLinkedList/main.c -o CMakeFiles/SinglyLinkedList.dir/main.c.s

CMakeFiles/SinglyLinkedList.dir/main.c.o.requires:

.PHONY : CMakeFiles/SinglyLinkedList.dir/main.c.o.requires

CMakeFiles/SinglyLinkedList.dir/main.c.o.provides: CMakeFiles/SinglyLinkedList.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/SinglyLinkedList.dir/build.make CMakeFiles/SinglyLinkedList.dir/main.c.o.provides.build
.PHONY : CMakeFiles/SinglyLinkedList.dir/main.c.o.provides

CMakeFiles/SinglyLinkedList.dir/main.c.o.provides.build: CMakeFiles/SinglyLinkedList.dir/main.c.o


# Object files for target SinglyLinkedList
SinglyLinkedList_OBJECTS = \
"CMakeFiles/SinglyLinkedList.dir/main.c.o"

# External object files for target SinglyLinkedList
SinglyLinkedList_EXTERNAL_OBJECTS =

SinglyLinkedList: CMakeFiles/SinglyLinkedList.dir/main.c.o
SinglyLinkedList: CMakeFiles/SinglyLinkedList.dir/build.make
SinglyLinkedList: CMakeFiles/SinglyLinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zosoist/CLionProjects/SinglyLinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SinglyLinkedList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SinglyLinkedList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SinglyLinkedList.dir/build: SinglyLinkedList

.PHONY : CMakeFiles/SinglyLinkedList.dir/build

CMakeFiles/SinglyLinkedList.dir/requires: CMakeFiles/SinglyLinkedList.dir/main.c.o.requires

.PHONY : CMakeFiles/SinglyLinkedList.dir/requires

CMakeFiles/SinglyLinkedList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SinglyLinkedList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SinglyLinkedList.dir/clean

CMakeFiles/SinglyLinkedList.dir/depend:
	cd /Users/zosoist/CLionProjects/SinglyLinkedList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zosoist/CLionProjects/SinglyLinkedList /Users/zosoist/CLionProjects/SinglyLinkedList /Users/zosoist/CLionProjects/SinglyLinkedList/cmake-build-debug /Users/zosoist/CLionProjects/SinglyLinkedList/cmake-build-debug /Users/zosoist/CLionProjects/SinglyLinkedList/cmake-build-debug/CMakeFiles/SinglyLinkedList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SinglyLinkedList.dir/depend

