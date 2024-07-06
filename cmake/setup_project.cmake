# file: setup_project.cmake
# author: Kumarjit Das
# date: 2024-07-04
# brief: MEM library cmake project setup file.

# License:
#
# Copyright (c) 2024, Kumarjit Das
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


# Setting the project name in lower, upper, and mixed case
set(MEM_PROJECT_NAME "mem")
string(TOLOWER ${MEM_PROJECT_NAME} MEM_PROJECT_NAME_LOWER)
string(TOUPPER ${MEM_PROJECT_NAME} MEM_PROJECT_NAME_UPPER)

# Setting the main library name in both lower and upper-cases
set(MEM_LIBRARY_NAME "mem")
string(TOUPPER ${MEM_LIBRARY_NAME} MEM_LIBRARY_NAME_UPPER)

# Setting project version
set(${MEM_LIBRARY_NAME_UPPER}_VERSION_MAJOR 1)
set(${MEM_LIBRARY_NAME_UPPER}_VERSION_MINOR 0)
set(${MEM_LIBRARY_NAME_UPPER}_VERSION_PATCH 0)

string(CONCAT ${MEM_LIBRARY_NAME_UPPER}_VERSION
  "${${MEM_LIBRARY_NAME_UPPER}_VERSION_MAJOR}."
  "${${MEM_LIBRARY_NAME_UPPER}_VERSION_MINOR}."
  "${${MEM_LIBRARY_NAME_UPPER}_VERSION_PATCH}")

# Setting project description
string(CONCAT ${MEM_PROJECT_NAME_UPPER}_DESCRIPTION
  "A simple C library designed to provide functionality for memory allocations with/without size information.")

set(MEM_INSTALL_DIR_NAME "${MEM_PROJECT_NAME_LOWER}-v${${MEM_LIBRARY_NAME_UPPER}_VERSION}")

# Creating the write_status function
function(write_status)
  set(STATUS_VARIABLE "")

  foreach(argument ${ARGV})
    set(STATUS_VARIABLE "${STATUS_VARIABLE}${argument}")
  endforeach()

  message(STATUS "[${MEM_PROJECT_NAME_UPPER}] ${STATUS_VARIABLE}")
endfunction()

write_status("Initiating the project setup.")

# Generate compile commands for IDE's
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

write_status("CMAKE_EXPORT_COMPILE_COMMANDS is set to: ${CMAKE_EXPORT_COMPILE_COMMANDS}")

# Setting the current user directory
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
  set(MEM_CURRENT_USER_PATH "C:/Users/$ENV{USERNAME}")
else()
  set(MEM_CURRENT_USER_PATH "/$ENV{USER}")
endif ()

write_status("Current user path: ${MEM_CURRENT_USER_PATH}")

# Getting the build directory name from current binary directory
string(REPLACE "${CMAKE_SOURCE_DIR}/" "" MEM_BUILD_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# By default build shared libraries
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# Setting the build library type name
if(BUILD_SHARED_LIBS)
  set(MEM_BUILD_LIBRARY_TYPE "Shared")
else()
  set(MEM_BUILD_LIBRARY_TYPE "Static")
endif()

# Setting the build directory name
string(FIND ${MEM_BUILD_DIRECTORY} ${MEM_BUILD_LIBRARY_TYPE} _MEM_BUILD_LIBRARY_TYPE_EXISTS)

if(${_MEM_BUILD_LIBRARY_TYPE_EXISTS} EQUAL -1)
  set(MEM_BUILD_DIRECTORY "${MEM_BUILD_DIRECTORY}-${MEM_BUILD_LIBRARY_TYPE}")
endif()
