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
CMAKE_SOURCE_DIR = /home/victor/cocos2d-x

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/victor/cocos2d-x/Game

# Include any dependencies generated for this target.
include engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/compiler_depend.make

# Include the progress variables for this target.
include engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/progress.make

# Include the compile flags for this target's objects.
include engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/flags.make

engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.o: engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/flags.make
engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.o: ../tests/lua-empty-test/project/Classes/AppDelegate.cpp
engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.o: engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/cocos2d-x/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.o"
	cd /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.o -MF CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.o.d -o CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.o -c /home/victor/cocos2d-x/tests/lua-empty-test/project/Classes/AppDelegate.cpp

engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.i"
	cd /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/cocos2d-x/tests/lua-empty-test/project/Classes/AppDelegate.cpp > CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.i

engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.s"
	cd /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/cocos2d-x/tests/lua-empty-test/project/Classes/AppDelegate.cpp -o CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.s

engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.o: engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/flags.make
engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.o: ../tests/lua-empty-test/project/proj.linux/main.cpp
engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.o: engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/cocos2d-x/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.o"
	cd /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.o -MF CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.o.d -o CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.o -c /home/victor/cocos2d-x/tests/lua-empty-test/project/proj.linux/main.cpp

engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.i"
	cd /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/cocos2d-x/tests/lua-empty-test/project/proj.linux/main.cpp > CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.i

engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.s"
	cd /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/cocos2d-x/tests/lua-empty-test/project/proj.linux/main.cpp -o CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.s

# Object files for target lua-empty-test
lua__empty__test_OBJECTS = \
"CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.o" \
"CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.o"

# External object files for target lua-empty-test
lua__empty__test_EXTERNAL_OBJECTS =

bin/lua-empty-test/lua-empty-test: engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/Classes/AppDelegate.cpp.o
bin/lua-empty-test/lua-empty-test: engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/proj.linux/main.cpp.o
bin/lua-empty-test/lua-empty-test: engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/build.make
bin/lua-empty-test/lua-empty-test: lib/libluacocos2d.a
bin/lua-empty-test/lua-empty-test: lib/libcocos2d.a
bin/lua-empty-test/lua-empty-test: lib/libexternal.a
bin/lua-empty-test/lua-empty-test: ../external/Box2D/prebuilt/linux/64-bit/libbox2d.a
bin/lua-empty-test/lua-empty-test: ../external/chipmunk/prebuilt/linux/64-bit/libchipmunk.a
bin/lua-empty-test/lua-empty-test: ../external/freetype2/prebuilt/linux/64-bit/libfreetype.a
bin/lua-empty-test/lua-empty-test: lib/libext_recast.a
bin/lua-empty-test/lua-empty-test: ../external/bullet/prebuilt/linux/64-bit/libLinearMath.a
bin/lua-empty-test/lua-empty-test: ../external/bullet/prebuilt/linux/64-bit/libBulletDynamics.a
bin/lua-empty-test/lua-empty-test: ../external/bullet/prebuilt/linux/64-bit/libBulletCollision.a
bin/lua-empty-test/lua-empty-test: ../external/bullet/prebuilt/linux/64-bit/libLinearMath.a
bin/lua-empty-test/lua-empty-test: ../external/bullet/prebuilt/linux/64-bit/libBulletMultiThreaded.a
bin/lua-empty-test/lua-empty-test: ../external/bullet/prebuilt/linux/64-bit/libMiniCL.a
bin/lua-empty-test/lua-empty-test: ../external/jpeg/prebuilt/linux/64-bit/libjpeg.a
bin/lua-empty-test/lua-empty-test: ../external/webp/prebuilt/linux/64-bit/libwebp.a
bin/lua-empty-test/lua-empty-test: ../external/websockets/prebuilt/linux/64-bit/libwebsockets.a
bin/lua-empty-test/lua-empty-test: ../external/openssl/prebuilt/linux/64-bit/libssl.a
bin/lua-empty-test/lua-empty-test: ../external/openssl/prebuilt/linux/64-bit/libcrypto.a
bin/lua-empty-test/lua-empty-test: ../external/uv/prebuilt/linux/64-bit/libuv_a.a
bin/lua-empty-test/lua-empty-test: lib/libext_tinyxml2.a
bin/lua-empty-test/lua-empty-test: lib/libext_xxhash.a
bin/lua-empty-test/lua-empty-test: lib/libext_xxtea.a
bin/lua-empty-test/lua-empty-test: lib/libext_clipper.a
bin/lua-empty-test/lua-empty-test: lib/libext_edtaa3func.a
bin/lua-empty-test/lua-empty-test: lib/libext_convertUTF.a
bin/lua-empty-test/lua-empty-test: lib/libext_poly2tri.a
bin/lua-empty-test/lua-empty-test: lib/libext_md5.a
bin/lua-empty-test/lua-empty-test: ../external/linux-specific/fmod/prebuilt/64-bit/libfmod.so
bin/lua-empty-test/lua-empty-test: ../external/glfw3/prebuilt/linux/libglfw3.a
bin/lua-empty-test/lua-empty-test: lib/libext_unzip.a
bin/lua-empty-test/lua-empty-test: /usr/lib/x86_64-linux-gnu/libz.so
bin/lua-empty-test/lua-empty-test: /usr/lib/x86_64-linux-gnu/libpng.so
bin/lua-empty-test/lua-empty-test: /usr/lib/x86_64-linux-gnu/libz.so
bin/lua-empty-test/lua-empty-test: /usr/lib/x86_64-linux-gnu/libpng.so
bin/lua-empty-test/lua-empty-test: /usr/lib/x86_64-linux-gnu/libGLEW.so
bin/lua-empty-test/lua-empty-test: /usr/lib/x86_64-linux-gnu/libGL.so
bin/lua-empty-test/lua-empty-test: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/lua-empty-test/lua-empty-test: /usr/lib/x86_64-linux-gnu/libcurl.so
bin/lua-empty-test/lua-empty-test: /usr/lib/x86_64-linux-gnu/libsqlite3.so
bin/lua-empty-test/lua-empty-test: ../external/lua/luajit/prebuilt/linux/64-bit/libluajit.a
bin/lua-empty-test/lua-empty-test: lib/libext_tolua.a
bin/lua-empty-test/lua-empty-test: lib/libext_luasocket.a
bin/lua-empty-test/lua-empty-test: engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/victor/cocos2d-x/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../bin/lua-empty-test/lua-empty-test"
	cd /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lua-empty-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/build: bin/lua-empty-test/lua-empty-test
.PHONY : engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/build

engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/clean:
	cd /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test && $(CMAKE_COMMAND) -P CMakeFiles/lua-empty-test.dir/cmake_clean.cmake
.PHONY : engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/clean

engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/depend:
	cd /home/victor/cocos2d-x/Game && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/victor/cocos2d-x /home/victor/cocos2d-x/tests/lua-empty-test/project /home/victor/cocos2d-x/Game /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test /home/victor/cocos2d-x/Game/engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/tests/lua-empty-test/CMakeFiles/lua-empty-test.dir/depend

