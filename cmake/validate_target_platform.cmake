# file: validate_target_platform.cmake
# author: Kumarjit Das
# date: 2024-07-04
# brief: MEM library cmake build configuration file.

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


# Defining lists of valid values
set(_VALID_TARGET_OS "windows" "linux")
set(_VALID_TARGET_ARCH "x86" "x64")

# Validate target OS configuration
write_status("Validating target OS configuration.")

if(NOT DEFINED KDAPI_TARGET_OS AND NOT DEFINED ${MEM_PROJECT_NAME_UPPER}_TARGET_OS)
  message(FATAL_ERROR "KDAPI_TARGET_OS or ${MEM_PROJECT_NAME_UPPER}_TARGET_OS is not provided.")
else()
  if(DEFINED KDAPI_TARGET_OS)
    set(${MEM_PROJECT_NAME_UPPER}_TARGET_OS ${KDAPI_TARGET_OS})
  endif()

  if(DEFINED ${MEM_PROJECT_NAME_UPPER}_TARGET_OS)
    set(KDAPI_TARGET_OS ${${MEM_PROJECT_NAME_UPPER}_TARGET_OS})
  endif()
endif()

# Validate the OS
list(FIND _VALID_TARGET_OS ${KDAPI_TARGET_OS} _OS_INDEX)
if(_OS_INDEX EQUAL -1)
  message(FATAL_ERROR "Unsupported target OS: ${KDAPI_TARGET_OS}. Supported values are ${_VALID_TARGET_OS}.")
endif()

# Validate target CPU architecture configuration
write_status("Validating target CPU architecture configuration.")

if(NOT DEFINED KDAPI_TARGET_ARCH AND NOT DEFINED ${MEM_PROJECT_NAME_UPPER}_TARGET_ARCH)
  message(FATAL_ERROR "KDAPI_TARGET_ARCH or ${MEM_PROJECT_NAME_UPPER}_TARGET_ARCH is not provided.")
else()
  if(DEFINED KDAPI_TARGET_ARCH)
    set(${MEM_PROJECT_NAME_UPPER}_TARGET_ARCH ${KDAPI_TARGET_ARCH})
  endif()

  if(DEFINED ${MEM_PROJECT_NAME_UPPER}_TARGET_ARCH)
    set(KDAPI_TARGET_ARCH ${${MEM_PROJECT_NAME_UPPER}_TARGET_ARCH})
  endif()
endif()

# Validate the OS
list(FIND _VALID_TARGET_ARCH ${KDAPI_TARGET_ARCH} _OS_INDEX)
if(_OS_INDEX EQUAL -1)
  message(FATAL_ERROR "Unsupported target CPU architecture: ${KDAPI_TARGET_ARCH}. "
    "Supported values are ${_VALID_TARGET_ARCH}.")
endif()

# Add the OS and CPU architecture to the installation directory name
set(MEM_INSTALL_DIR_NAME "${MEM_INSTALL_DIR_NAME}-${KDAPI_TARGET_OS}-${KDAPI_TARGET_ARCH}")
