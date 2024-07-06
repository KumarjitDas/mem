/**
 * @file mem.c
 * @author Kumarjit Das
 * @date 2024-07-07
 * @version @KDAPI_VERSION_MAJOR@.@KDAPI_VERSION_MINOR@.@KDAPI_VERSION_PATCH@
 * @brief Main source file of the MEM library.
 */
/**
 * LICENSE:
 *
 * Copyright (c) 2024, Kumarjit Das
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#define KD_BUILDING_LIB 1
#include "mem.h"

#include <stdio.h>
#include <stdlib.h>


MEMAPI(bool) kd_mem__func_memAlloc_(void* dst, i32 sz, const char* file, i32 line, FILE* f)
{
  (void) dst;
  (void) sz;
  (void) file;
  (void) line;
  return MEM_FAILURE;
}

MEMAPI(bool) kd_mem__func_memRealloc_(void* dst, void* src, i32 sz, const char* file, i32 line, FILE* f)
{
  (void) dst;
  (void) src;
  (void) sz;
  (void) file;
  (void) line;
  return MEM_FAILURE;
}

MEMAPI(bool) kd_mem__func_memFree_(void* dst, const char* file, i32 line, FILE* f)
{
  (void) dst;
  (void) file;
  (void) line;
  return MEM_FAILURE;
}

MEMAPI(bool) kd_mem__func_memAllocWithSizeInfo_(void* dst, i32 sz, const char* file, i32 line, FILE* f)
{
  (void) dst;
  (void) sz;
  (void) file;
  (void) line;
  return MEM_FAILURE;
}

MEMAPI(bool) kd_mem__func_memReallocWithSizeInfo_(void* dst, void* src, i32 sz, const char* file, i32 line, FILE* f)
{
  (void) dst;
  (void) src;
  (void) sz;
  (void) file;
  (void) line;
  return MEM_FAILURE;
}

MEMAPI(bool) kd_mem__func_memFreeWithSizeInfo_(void* dst, const char* file, i32 line, FILE* f)
{
  (void) dst;
  (void) file;
  (void) line;
  return MEM_FAILURE;
}

MEMAPI(bool) memAlloc(void* dst, i32 sz)
{
  u8* ptr;

  if (dst == null)
  {
    return MEM_FAILURE;
  }

  if (sz <= 0)
  {
    *(u8**) dst = null;
    return MEM_FAILURE;
  }

  ptr = (u8*) malloc((size_t) sz);

  if (ptr == null)
  {
    *(u8**) dst = null;
    return MEM_FAILURE;
  }

  *(u8**) dst = ptr;

  return MEM_SUCCESS;
}

MEMAPI(bool) memRealloc(void* dst, void* src, i32 sz)
{
  u8* ptr;

  if (dst == null)
  {
    return MEM_FAILURE;
  }

  *(u8**) dst = null;

  if (src == null)
  {
    return MEM_FAILURE;
  }

  if (sz <= 0)
  {
    return MEM_FAILURE;
  }

  ptr = (u8*) realloc(*(void**) src, (size_t) sz);
  *(u8**) src = null;

  if (ptr == null)
  {
    return MEM_FAILURE;
  }

  *(u8**) dst = ptr;

  return MEM_SUCCESS;
}

MEMAPI(bool) memFree(void* dst)
{
  if (dst == null)
  {
    return MEM_FAILURE;
  }

  free(*(u8**) dst);
  *(u8**) dst = null;

  return MEM_SUCCESS;
}

MEMAPI(bool) memAllocWithSizeInfo(void* dst, i32 sz)
{
  (void) dst;
  (void) sz;
  return MEM_FAILURE;
}

MEMAPI(bool) memReallocWithSizeInfo(void* dst, void* src, i32 sz)
{
  (void) dst;
  (void) src;
  (void) sz;
  return MEM_FAILURE;
}

MEMAPI(bool) memFreeWithSizeInfo(void* dst)
{
  (void) dst;
  return MEM_FAILURE;
}
