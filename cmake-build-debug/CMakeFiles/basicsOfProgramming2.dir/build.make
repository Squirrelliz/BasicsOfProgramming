# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lizka\CLionProjects\basicsOfProgramming2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lizka\CLionProjects\basicsOfProgramming2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/basicsOfProgramming2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/basicsOfProgramming2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basicsOfProgramming2.dir/flags.make

CMakeFiles/basicsOfProgramming2.dir/main.c.obj: CMakeFiles/basicsOfProgramming2.dir/flags.make
CMakeFiles/basicsOfProgramming2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lizka\CLionProjects\basicsOfProgramming2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/basicsOfProgramming2.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\basicsOfProgramming2.dir\main.c.obj -c C:\Users\lizka\CLionProjects\basicsOfProgramming2\main.c

CMakeFiles/basicsOfProgramming2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/basicsOfProgramming2.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lizka\CLionProjects\basicsOfProgramming2\main.c > CMakeFiles\basicsOfProgramming2.dir\main.c.i

CMakeFiles/basicsOfProgramming2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/basicsOfProgramming2.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lizka\CLionProjects\basicsOfProgramming2\main.c -o CMakeFiles\basicsOfProgramming2.dir\main.c.s

# Object files for target basicsOfProgramming2
basicsOfProgramming2_OBJECTS = \
"CMakeFiles/basicsOfProgramming2.dir/main.c.obj"

# External object files for target basicsOfProgramming2
basicsOfProgramming2_EXTERNAL_OBJECTS =

basicsOfProgramming2.exe: CMakeFiles/basicsOfProgramming2.dir/main.c.obj
basicsOfProgramming2.exe: CMakeFiles/basicsOfProgramming2.dir/build.make
basicsOfProgramming2.exe: libs/algorithms/libalgorithms.a
basicsOfProgramming2.exe: libs/data_structures/libdata_structures.a
basicsOfProgramming2.exe: CMakeFiles/basicsOfProgramming2.dir/linklibs.rsp
basicsOfProgramming2.exe: CMakeFiles/basicsOfProgramming2.dir/objects1.rsp
basicsOfProgramming2.exe: CMakeFiles/basicsOfProgramming2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lizka\CLionProjects\basicsOfProgramming2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable basicsOfProgramming2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\basicsOfProgramming2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basicsOfProgramming2.dir/build: basicsOfProgramming2.exe
.PHONY : CMakeFiles/basicsOfProgramming2.dir/build

CMakeFiles/basicsOfProgramming2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\basicsOfProgramming2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/basicsOfProgramming2.dir/clean

CMakeFiles/basicsOfProgramming2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lizka\CLionProjects\basicsOfProgramming2 C:\Users\lizka\CLionProjects\basicsOfProgramming2 C:\Users\lizka\CLionProjects\basicsOfProgramming2\cmake-build-debug C:\Users\lizka\CLionProjects\basicsOfProgramming2\cmake-build-debug C:\Users\lizka\CLionProjects\basicsOfProgramming2\cmake-build-debug\CMakeFiles\basicsOfProgramming2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/basicsOfProgramming2.dir/depend

