# file: export_rules.cmake
# author: Kumarjit Das
# date: 2024-07-04
# brief: MEM library cmake export rules file.

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


write_status("Generating ${MEM_PROJECT_NAME_LOWER}-targets.")

# Adding this to make cache variables for install destinations
include("GNUInstallDirs")

# Creating export target for the main library
install(
  TARGETS              ${MEM_LIBRARY_NAME}
  EXPORT               ${MEM_PROJECT_NAME_LOWER}-targets
  LIBRARY  DESTINATION "${MEM_INSTALL_DIR_NAME}/${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE  DESTINATION "${MEM_INSTALL_DIR_NAME}/${CMAKE_INSTALL_LIBDIR}"
  RUNTIME  DESTINATION "${MEM_INSTALL_DIR_NAME}/${CMAKE_INSTALL_BINDIR}"
  INCLUDES DESTINATION "${MEM_INSTALL_DIR_NAME}/${CMAKE_INSTALL_INCLUDEDIR}"
)

# Setting the install location of the generated export target file
install(
  EXPORT      ${MEM_PROJECT_NAME_LOWER}-targets
  FILE        "${MEM_PROJECT_NAME_LOWER}-targets.cmake"
  NAMESPACE   KDAPI::
  DESTINATION "${MEM_INSTALL_DIR_NAME}/${CMAKE_INSTALL_LIBDIR}/${MEM_INSTALL_CMAKE_DIR}"
)

# Rule to export all the targets directly from the build-tree
export(
  EXPORT ${MEM_PROJECT_NAME_LOWER}-targets
  FILE "${PROJECT_BINARY_DIR}/${MEM_PROJECT_NAME_LOWER}-targets.cmake"
  NAMESPACE KDAPI::
)
