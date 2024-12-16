# Install script for directory: C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/sfml-build/lib/oggd.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ogg" TYPE FILE FILES
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-build/include/ogg/config_types.h"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/include/ogg/ogg.h"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/include/ogg/os_types.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Ogg/OggTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Ogg/OggTargets.cmake"
         "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-build/CMakeFiles/Export/dee6fd410a50d06b294b496f57355584/OggTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Ogg/OggTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Ogg/OggTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Ogg" TYPE FILE FILES "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-build/CMakeFiles/Export/dee6fd410a50d06b294b496f57355584/OggTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Ogg" TYPE FILE FILES "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-build/CMakeFiles/Export/dee6fd410a50d06b294b496f57355584/OggTargets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Ogg" TYPE FILE FILES
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-build/OggConfig.cmake"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-build/OggConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-build/ogg.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SFML/html" TYPE FILE FILES
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/framing.html"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/index.html"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/oggstream.html"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/ogg-multiplex.html"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/fish_xiph_org.png"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/multiplex1.png"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/packets.png"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/pages.png"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/stream.png"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/vorbisword2.png"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/white-ogg.png"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/white-xifish.png"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/rfc3533.txt"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/rfc5334.txt"
    "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/skeleton.html"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SFML/html" TYPE DIRECTORY FILES "C:/Users/eguignabaudet/Documents/GitHub/GC04_Template/out/build/x64-Debug/_deps/ogg-src/doc/libogg")
endif()

