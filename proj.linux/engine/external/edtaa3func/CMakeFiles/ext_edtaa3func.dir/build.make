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
CMAKE_SOURCE_DIR = /home/victor/cocos2d-x/Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/victor/cocos2d-x/Game/proj.linux

# Include any dependencies generated for this target.
include engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/compiler_depend.make

# Include the progress variables for this target.
include engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/progress.make

# Include the compile flags for this target's objects.
include engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/flags.make

engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.o: engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/flags.make
engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.o: ../cocos2d/external/edtaa3func/edtaa3func.cpp
engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.o: engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/cocos2d-x/Game/proj.linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.o"
	cd /home/victor/cocos2d-x/Game/proj.linux/engine/external/edtaa3func && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.o -MF CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.o.d -o CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.o -c /home/victor/cocos2d-x/Game/cocos2d/external/edtaa3func/edtaa3func.cpp

engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.i"
	cd /home/victor/cocos2d-x/Game/proj.linux/engine/external/edtaa3func && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/cocos2d-x/Game/cocos2d/external/edtaa3func/edtaa3func.cpp > CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.i

engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.s"
	cd /home/victor/cocos2d-x/Game/proj.linux/engine/external/edtaa3func && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/cocos2d-x/Game/cocos2d/external/edtaa3func/edtaa3func.cpp -o CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.s

# Object files for target ext_edtaa3func
ext_edtaa3func_OBJECTS = \
"CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.o"

# External object files for target ext_edtaa3func
ext_edtaa3func_EXTERNAL_OBJECTS =

lib/libext_edtaa3func.a: engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/edtaa3func.cpp.o
lib/libext_edtaa3func.a: engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/build.make
lib/libext_edtaa3func.a: engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/victor/cocos2d-x/Game/proj.linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libext_edtaa3func.a"
	cd /home/victor/cocos2d-x/Game/proj.linux/engine/external/edtaa3func && $(CMAKE_COMMAND) -P CMakeFiles/ext_edtaa3func.dir/cmake_clean_target.cmake
	cd /home/victor/cocos2d-x/Game/proj.linux/engine/external/edtaa3func && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ext_edtaa3func.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/build: lib/libext_edtaa3func.a
.PHONY : engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/build

engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/clean:
	cd /home/victor/cocos2d-x/Game/proj.linux/engine/external/edtaa3func && $(CMAKE_COMMAND) -P CMakeFiles/ext_edtaa3func.dir/cmake_clean.cmake
.PHONY : engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/clean

engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/depend:
	cd /home/victor/cocos2d-x/Game/proj.linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/victor/cocos2d-x/Game /home/victor/cocos2d-x/Game/cocos2d/external/edtaa3func /home/victor/cocos2d-x/Game/proj.linux /home/victor/cocos2d-x/Game/proj.linux/engine/external/edtaa3func /home/victor/cocos2d-x/Game/proj.linux/engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/external/edtaa3func/CMakeFiles/ext_edtaa3func.dir/depend

