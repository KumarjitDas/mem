# file: set_install_directories.cmake
# author: Kumarjit Das
# date: 2024-07-04
# brief: MEM library cmake install directories configuration file.

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


# Offer the user the choice of overriding the installation directories
set(MEM_INSTALL_LIB_DIR "${MEM_PROJECT_NAME_LOWER}/lib" CACHE PATH "Installation directory for libraries")
set(MEM_INSTALL_BIN_DIR "${MEM_PROJECT_NAME_LOWER}/bin" CACHE PATH "Installation directory for executables")
set(MEM_INSTALL_INCLUDE_DIR "${MEM_PROJECT_NAME_LOWER}/include" CACHE PATH
  "Installation directory for header files")
set(MEM_INSTALL_CMAKE_DIR "cmake" CACHE PATH "Installation directory for CMake files")

write_status("Install lib dir set to: ${MEM_INSTALL_LIB_DIR}")
write_status("Install bin dir set to: ${MEM_INSTALL_BIN_DIR}")
write_status("Install include dir set to: ${MEM_INSTALL_INCLUDE_DIR}")
write_status("Install cmake dir set to: ${MEM_INSTALL_CMAKE_DIR}")

# Setting the installation directory of the kdapi library
set(KDAPI_INSTALL_CMAKE_DIR "cmake/kdapi" CACHE PATH "Installation directory for kdapi CMake files")

# Setting the installation directory of the types library
set(TYPES_INSTALL_CMAKE_DIR "cmake/types" CACHE PATH "Installation directory for types CMake files")
