# file: CMakeLists.txt
# author: Kumarjit Das
# date: 2024-07-07
# brief: MEM library main cmake file.

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


cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

# Setup all project settings/variables
include("CMake/setup_project.cmake")

# Setting the project name, version, and other descriptions
project(${MEM_PROJECT_NAME}
  VERSION      "${${MEM_LIBRARY_NAME_UPPER}_VERSION}"
  DESCRIPTION  "${${MEM_PROJECT_NAME_UPPER}_DESCRIPTION}"
  HOMEPAGE_URL "https://github.com/KumarjitDas/mem.git"
  LANGUAGES    C)

# Validate target platform
include("CMake/validate_target_platform.cmake")

# Validate the build configuration
include("CMake/validate_build_config.cmake")

# Fetch external libraries
include("cmake/add_external_libs.cmake")

# Create the main library
include("CMake/create_library.cmake")

# Add sources to the library
include("CMake/add_sources_to_target.cmake")

# Set the build output directories
include("CMake/set_build_output_directories.cmake")

# Set the installation directories
include("CMake/set_install_directories.cmake")

# Set the C standard
include("CMake/set_c_standard.cmake")

# Set the compiler flags/warnings
include("cmake/set_compiler_flags.cmake")

# Set include directories
include("CMake/set_include_directories.cmake")

# Set build postfixes for different build configurations
include("CMake/set_build_postfixes.cmake")

# Configure the versions of this project
include("CMake/configure_project_version.cmake")

# Add the source files to the main target
include("CMake/export_rules.cmake")

# Adding the package configuration for `find_package` support
include("CMake/package_configuration.cmake")

# Install all non-project files
include("CMake/install_nonproject_files.cmake")

# Add tests for the target
include("CMake/include_tests.cmake")

# Adding the `Examples` directories
add_subdirectory("examples")
