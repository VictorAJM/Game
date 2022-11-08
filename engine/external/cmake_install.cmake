# Install script for directory: /home/victor/cocos2d-x/external

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/victor/cocos2d-x/Game/engine/external/Box2D/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/chipmunk/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/freetype2/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/recast/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/bullet/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/jpeg/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/openssl/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/uv/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/webp/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/websockets/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/tinyxml2/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/xxhash/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/xxtea/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/clipper/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/edtaa3func/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/ConvertUTF/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/poly2tri/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/md5/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/lua/luajit/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/lua/tolua/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/lua/luasocket/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/linux-specific/fmod/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/glfw3/cmake_install.cmake")
  include("/home/victor/cocos2d-x/Game/engine/external/unzip/cmake_install.cmake")

endif()

