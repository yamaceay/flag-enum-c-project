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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Applications/uni/rnvs/C-Flags

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Applications/uni/rnvs/C-Flags

# Include any dependencies generated for this target.
include CMakeFiles/Util-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Util-test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Util-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Util-test.dir/flags.make

CMakeFiles/Util-test.dir/tests/util_test.c.o: CMakeFiles/Util-test.dir/flags.make
CMakeFiles/Util-test.dir/tests/util_test.c.o: tests/util_test.c
CMakeFiles/Util-test.dir/tests/util_test.c.o: CMakeFiles/Util-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Applications/uni/rnvs/C-Flags/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Util-test.dir/tests/util_test.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Util-test.dir/tests/util_test.c.o -MF CMakeFiles/Util-test.dir/tests/util_test.c.o.d -o CMakeFiles/Util-test.dir/tests/util_test.c.o -c /Applications/uni/rnvs/C-Flags/tests/util_test.c

CMakeFiles/Util-test.dir/tests/util_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Util-test.dir/tests/util_test.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Applications/uni/rnvs/C-Flags/tests/util_test.c > CMakeFiles/Util-test.dir/tests/util_test.c.i

CMakeFiles/Util-test.dir/tests/util_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Util-test.dir/tests/util_test.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Applications/uni/rnvs/C-Flags/tests/util_test.c -o CMakeFiles/Util-test.dir/tests/util_test.c.s

CMakeFiles/Util-test.dir/src/util.c.o: CMakeFiles/Util-test.dir/flags.make
CMakeFiles/Util-test.dir/src/util.c.o: src/util.c
CMakeFiles/Util-test.dir/src/util.c.o: CMakeFiles/Util-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Applications/uni/rnvs/C-Flags/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Util-test.dir/src/util.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Util-test.dir/src/util.c.o -MF CMakeFiles/Util-test.dir/src/util.c.o.d -o CMakeFiles/Util-test.dir/src/util.c.o -c /Applications/uni/rnvs/C-Flags/src/util.c

CMakeFiles/Util-test.dir/src/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Util-test.dir/src/util.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Applications/uni/rnvs/C-Flags/src/util.c > CMakeFiles/Util-test.dir/src/util.c.i

CMakeFiles/Util-test.dir/src/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Util-test.dir/src/util.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Applications/uni/rnvs/C-Flags/src/util.c -o CMakeFiles/Util-test.dir/src/util.c.s

# Object files for target Util-test
Util__test_OBJECTS = \
"CMakeFiles/Util-test.dir/tests/util_test.c.o" \
"CMakeFiles/Util-test.dir/src/util.c.o"

# External object files for target Util-test
Util__test_EXTERNAL_OBJECTS =

Outputs/Util-out: CMakeFiles/Util-test.dir/tests/util_test.c.o
Outputs/Util-out: CMakeFiles/Util-test.dir/src/util.c.o
Outputs/Util-out: CMakeFiles/Util-test.dir/build.make
Outputs/Util-out: CMakeFiles/Util-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Applications/uni/rnvs/C-Flags/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Outputs/Util-out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Util-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Util-test.dir/build: Outputs/Util-out
.PHONY : CMakeFiles/Util-test.dir/build

CMakeFiles/Util-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Util-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Util-test.dir/clean

CMakeFiles/Util-test.dir/depend:
	cd /Applications/uni/rnvs/C-Flags && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Applications/uni/rnvs/C-Flags /Applications/uni/rnvs/C-Flags /Applications/uni/rnvs/C-Flags /Applications/uni/rnvs/C-Flags /Applications/uni/rnvs/C-Flags/CMakeFiles/Util-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Util-test.dir/depend

