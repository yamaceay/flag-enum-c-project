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
include CMakeFiles/_Flag-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/_Flag-test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/_Flag-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_Flag-test.dir/flags.make

CMakeFiles/_Flag-test.dir/tests/flag_test.c.o: CMakeFiles/_Flag-test.dir/flags.make
CMakeFiles/_Flag-test.dir/tests/flag_test.c.o: tests/flag_test.c
CMakeFiles/_Flag-test.dir/tests/flag_test.c.o: CMakeFiles/_Flag-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Applications/uni/rnvs/C-Flags/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/_Flag-test.dir/tests/flag_test.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/_Flag-test.dir/tests/flag_test.c.o -MF CMakeFiles/_Flag-test.dir/tests/flag_test.c.o.d -o CMakeFiles/_Flag-test.dir/tests/flag_test.c.o -c /Applications/uni/rnvs/C-Flags/tests/flag_test.c

CMakeFiles/_Flag-test.dir/tests/flag_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_Flag-test.dir/tests/flag_test.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Applications/uni/rnvs/C-Flags/tests/flag_test.c > CMakeFiles/_Flag-test.dir/tests/flag_test.c.i

CMakeFiles/_Flag-test.dir/tests/flag_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_Flag-test.dir/tests/flag_test.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Applications/uni/rnvs/C-Flags/tests/flag_test.c -o CMakeFiles/_Flag-test.dir/tests/flag_test.c.s

CMakeFiles/_Flag-test.dir/src/flag.c.o: CMakeFiles/_Flag-test.dir/flags.make
CMakeFiles/_Flag-test.dir/src/flag.c.o: src/flag.c
CMakeFiles/_Flag-test.dir/src/flag.c.o: CMakeFiles/_Flag-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Applications/uni/rnvs/C-Flags/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/_Flag-test.dir/src/flag.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/_Flag-test.dir/src/flag.c.o -MF CMakeFiles/_Flag-test.dir/src/flag.c.o.d -o CMakeFiles/_Flag-test.dir/src/flag.c.o -c /Applications/uni/rnvs/C-Flags/src/flag.c

CMakeFiles/_Flag-test.dir/src/flag.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_Flag-test.dir/src/flag.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Applications/uni/rnvs/C-Flags/src/flag.c > CMakeFiles/_Flag-test.dir/src/flag.c.i

CMakeFiles/_Flag-test.dir/src/flag.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_Flag-test.dir/src/flag.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Applications/uni/rnvs/C-Flags/src/flag.c -o CMakeFiles/_Flag-test.dir/src/flag.c.s

CMakeFiles/_Flag-test.dir/src/bool.c.o: CMakeFiles/_Flag-test.dir/flags.make
CMakeFiles/_Flag-test.dir/src/bool.c.o: src/bool.c
CMakeFiles/_Flag-test.dir/src/bool.c.o: CMakeFiles/_Flag-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Applications/uni/rnvs/C-Flags/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/_Flag-test.dir/src/bool.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/_Flag-test.dir/src/bool.c.o -MF CMakeFiles/_Flag-test.dir/src/bool.c.o.d -o CMakeFiles/_Flag-test.dir/src/bool.c.o -c /Applications/uni/rnvs/C-Flags/src/bool.c

CMakeFiles/_Flag-test.dir/src/bool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_Flag-test.dir/src/bool.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Applications/uni/rnvs/C-Flags/src/bool.c > CMakeFiles/_Flag-test.dir/src/bool.c.i

CMakeFiles/_Flag-test.dir/src/bool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_Flag-test.dir/src/bool.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Applications/uni/rnvs/C-Flags/src/bool.c -o CMakeFiles/_Flag-test.dir/src/bool.c.s

# Object files for target _Flag-test
_Flag__test_OBJECTS = \
"CMakeFiles/_Flag-test.dir/tests/flag_test.c.o" \
"CMakeFiles/_Flag-test.dir/src/flag.c.o" \
"CMakeFiles/_Flag-test.dir/src/bool.c.o"

# External object files for target _Flag-test
_Flag__test_EXTERNAL_OBJECTS =

Outputs/Flag-out: CMakeFiles/_Flag-test.dir/tests/flag_test.c.o
Outputs/Flag-out: CMakeFiles/_Flag-test.dir/src/flag.c.o
Outputs/Flag-out: CMakeFiles/_Flag-test.dir/src/bool.c.o
Outputs/Flag-out: CMakeFiles/_Flag-test.dir/build.make
Outputs/Flag-out: CMakeFiles/_Flag-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Applications/uni/rnvs/C-Flags/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Outputs/Flag-out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_Flag-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_Flag-test.dir/build: Outputs/Flag-out
.PHONY : CMakeFiles/_Flag-test.dir/build

CMakeFiles/_Flag-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_Flag-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_Flag-test.dir/clean

CMakeFiles/_Flag-test.dir/depend:
	cd /Applications/uni/rnvs/C-Flags && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Applications/uni/rnvs/C-Flags /Applications/uni/rnvs/C-Flags /Applications/uni/rnvs/C-Flags /Applications/uni/rnvs/C-Flags /Applications/uni/rnvs/C-Flags/CMakeFiles/_Flag-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/_Flag-test.dir/depend

