# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/build

# Include any dependencies generated for this target.
include CMakeFiles/example2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/example2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/example2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example2.dir/flags.make

CMakeFiles/example2.dir/example2.cpp.obj: CMakeFiles/example2.dir/flags.make
CMakeFiles/example2.dir/example2.cpp.obj: CMakeFiles/example2.dir/includes_CXX.rsp
CMakeFiles/example2.dir/example2.cpp.obj: C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/example2.cpp
CMakeFiles/example2.dir/example2.cpp.obj: CMakeFiles/example2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example2.dir/example2.cpp.obj"
	C:/Windows/w64devkit/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/example2.dir/example2.cpp.obj -MF CMakeFiles/example2.dir/example2.cpp.obj.d -o CMakeFiles/example2.dir/example2.cpp.obj -c C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/example2.cpp

CMakeFiles/example2.dir/example2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example2.dir/example2.cpp.i"
	C:/Windows/w64devkit/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/example2.cpp > CMakeFiles/example2.dir/example2.cpp.i

CMakeFiles/example2.dir/example2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example2.dir/example2.cpp.s"
	C:/Windows/w64devkit/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/example2.cpp -o CMakeFiles/example2.dir/example2.cpp.s

# Object files for target example2
example2_OBJECTS = \
"CMakeFiles/example2.dir/example2.cpp.obj"

# External object files for target example2
example2_EXTERNAL_OBJECTS =

example2.exe: CMakeFiles/example2.dir/example2.cpp.obj
example2.exe: CMakeFiles/example2.dir/build.make
example2.exe: bin/libyyjson.a
example2.exe: CMakeFiles/example2.dir/linkLibs.rsp
example2.exe: CMakeFiles/example2.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example2.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/example2.dir/objects.a
	C:/Windows/w64devkit/bin/ar.exe qc CMakeFiles/example2.dir/objects.a @CMakeFiles/example2.dir/objects1.rsp
	C:/Windows/w64devkit/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/example2.dir/objects.a -Wl,--no-whole-archive -o example2.exe -Wl,--out-implib,libexample2.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/example2.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/example2.dir/build: example2.exe
.PHONY : CMakeFiles/example2.dir/build

CMakeFiles/example2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example2.dir/clean

CMakeFiles/example2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/build C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/build C:/Users/mchao/Desktop/QQdemo/testILIB/yyjson/build/CMakeFiles/example2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example2.dir/depend

