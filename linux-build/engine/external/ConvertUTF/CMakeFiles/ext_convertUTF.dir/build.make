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
CMAKE_BINARY_DIR = /home/victor/cocos2d-x/Game/linux-build

# Include any dependencies generated for this target.
include engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/compiler_depend.make

# Include the progress variables for this target.
include engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/progress.make

# Include the compile flags for this target's objects.
include engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/flags.make

engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.o: engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/flags.make
engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.o: ../cocos2d/external/ConvertUTF/ConvertUTF.c
engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.o: engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/cocos2d-x/Game/linux-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.o"
	cd /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.o -MF CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.o.d -o CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.o -c /home/victor/cocos2d-x/Game/cocos2d/external/ConvertUTF/ConvertUTF.c

engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.i"
	cd /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/victor/cocos2d-x/Game/cocos2d/external/ConvertUTF/ConvertUTF.c > CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.i

engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.s"
	cd /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/victor/cocos2d-x/Game/cocos2d/external/ConvertUTF/ConvertUTF.c -o CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.s

engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.o: engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/flags.make
engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.o: ../cocos2d/external/ConvertUTF/ConvertUTFWrapper.cpp
engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.o: engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/cocos2d-x/Game/linux-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.o"
	cd /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.o -MF CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.o.d -o CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.o -c /home/victor/cocos2d-x/Game/cocos2d/external/ConvertUTF/ConvertUTFWrapper.cpp

engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.i"
	cd /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/cocos2d-x/Game/cocos2d/external/ConvertUTF/ConvertUTFWrapper.cpp > CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.i

engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.s"
	cd /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/cocos2d-x/Game/cocos2d/external/ConvertUTF/ConvertUTFWrapper.cpp -o CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.s

# Object files for target ext_convertUTF
ext_convertUTF_OBJECTS = \
"CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.o" \
"CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.o"

# External object files for target ext_convertUTF
ext_convertUTF_EXTERNAL_OBJECTS =

lib/libext_convertUTF.a: engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTF.c.o
lib/libext_convertUTF.a: engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/ConvertUTFWrapper.cpp.o
lib/libext_convertUTF.a: engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/build.make
lib/libext_convertUTF.a: engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/victor/cocos2d-x/Game/linux-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../../lib/libext_convertUTF.a"
	cd /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF && $(CMAKE_COMMAND) -P CMakeFiles/ext_convertUTF.dir/cmake_clean_target.cmake
	cd /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ext_convertUTF.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/build: lib/libext_convertUTF.a
.PHONY : engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/build

engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/clean:
	cd /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF && $(CMAKE_COMMAND) -P CMakeFiles/ext_convertUTF.dir/cmake_clean.cmake
.PHONY : engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/clean

engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/depend:
	cd /home/victor/cocos2d-x/Game/linux-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/victor/cocos2d-x/Game /home/victor/cocos2d-x/Game/cocos2d/external/ConvertUTF /home/victor/cocos2d-x/Game/linux-build /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF /home/victor/cocos2d-x/Game/linux-build/engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/external/ConvertUTF/CMakeFiles/ext_convertUTF.dir/depend

