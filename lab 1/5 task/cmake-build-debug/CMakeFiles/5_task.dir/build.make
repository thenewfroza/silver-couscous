# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "F:\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "F:\Labs\1 sem\algo\1 lab\5 task"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\Labs\1 sem\algo\1 lab\5 task\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/5_task.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/5_task.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/5_task.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5_task.dir/flags.make

CMakeFiles/5_task.dir/main.cpp.obj: CMakeFiles/5_task.dir/flags.make
CMakeFiles/5_task.dir/main.cpp.obj: ../main.cpp
CMakeFiles/5_task.dir/main.cpp.obj: CMakeFiles/5_task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Labs\1 sem\algo\1 lab\5 task\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/5_task.dir/main.cpp.obj"
	"F:\CLion 2022.2.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/5_task.dir/main.cpp.obj -MF CMakeFiles\5_task.dir\main.cpp.obj.d -o CMakeFiles\5_task.dir\main.cpp.obj -c "F:\Labs\1 sem\algo\1 lab\5 task\main.cpp"

CMakeFiles/5_task.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/5_task.dir/main.cpp.i"
	"F:\CLion 2022.2.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Labs\1 sem\algo\1 lab\5 task\main.cpp" > CMakeFiles\5_task.dir\main.cpp.i

CMakeFiles/5_task.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/5_task.dir/main.cpp.s"
	"F:\CLion 2022.2.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\Labs\1 sem\algo\1 lab\5 task\main.cpp" -o CMakeFiles\5_task.dir\main.cpp.s

# Object files for target 5_task
5_task_OBJECTS = \
"CMakeFiles/5_task.dir/main.cpp.obj"

# External object files for target 5_task
5_task_EXTERNAL_OBJECTS =

5_task.exe: CMakeFiles/5_task.dir/main.cpp.obj
5_task.exe: CMakeFiles/5_task.dir/build.make
5_task.exe: CMakeFiles/5_task.dir/linklibs.rsp
5_task.exe: CMakeFiles/5_task.dir/objects1.rsp
5_task.exe: CMakeFiles/5_task.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\Labs\1 sem\algo\1 lab\5 task\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 5_task.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\5_task.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5_task.dir/build: 5_task.exe
.PHONY : CMakeFiles/5_task.dir/build

CMakeFiles/5_task.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\5_task.dir\cmake_clean.cmake
.PHONY : CMakeFiles/5_task.dir/clean

CMakeFiles/5_task.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\Labs\1 sem\algo\1 lab\5 task" "F:\Labs\1 sem\algo\1 lab\5 task" "F:\Labs\1 sem\algo\1 lab\5 task\cmake-build-debug" "F:\Labs\1 sem\algo\1 lab\5 task\cmake-build-debug" "F:\Labs\1 sem\algo\1 lab\5 task\cmake-build-debug\CMakeFiles\5_task.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/5_task.dir/depend

