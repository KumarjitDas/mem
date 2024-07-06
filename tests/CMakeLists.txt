# file: CMakeLists.txt
# author: Kumarjit Das
# date: 2024-07-07
# brief: MEM library tests cmake file.

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


write_status("'tests' subdirectory added.")

include(GoogleTest)

# Get all .cpp files in the directory
file(GLOB ALL_C_FILES "*.cpp")

# Initialize an empty list to store file names without extensions
set(TEST_LIST "")

# Loop over each file and extract the name without extension
foreach(FILE_PATH ${ALL_C_FILES})
  get_filename_component(FILE_NAME_WE ${FILE_PATH} NAME_WE)
  list(APPEND TEST_LIST ${FILE_NAME_WE})
endforeach()

# Loop through each item in the examples list
foreach(TEST_ITEM ${TEST_LIST})
  # Attaching library name in front of example item
  set(TEST_TARGET "${MEM_PROJECT_NAME_LOWER}-${TEST_ITEM}")

  # Build an executable from the `TEST_ITEM` source
  add_executable(${TEST_TARGET} "${TEST_ITEM}.cpp")

  # Link the built executable with the main library
  target_link_libraries(${TEST_TARGET} PRIVATE "KDAPI::${MEM_LIBRARY_NAME}" GTest::gtest_main)

  # Setting build postfixes for different build configurations
  set_target_properties(
    ${TEST_TARGET}         PROPERTIES
    DEBUG_POSTFIX          "${MEM_STATIC_POSTFIX}-d"
    RELEASE_POSTFIX        "${MEM_STATIC_POSTFIX}"
    MINSIZEREL_POSTFIX     "${MEM_STATIC_POSTFIX}-mr"
    RELWITHDEBINFO_POSTFIX "${MEM_STATIC_POSTFIX}-rd"
  )

  # Check if the project builds shared libraries
  if(BUILD_SHARED_LIBS)
    set_target_properties(
      ${TEST_TARGET}           PROPERTIES
      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
  endif()

  gtest_discover_tests(${TEST_TARGET})
  write_status("Adding test: ${TEST_TARGET}")
endforeach()
