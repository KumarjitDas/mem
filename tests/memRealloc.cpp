/**
 * @file memRealloc.cpp
 * @author Kumarjit Das
 * @date 2024-07-07
 * @version @KDAPI_VERSION_MAJOR@.@KDAPI_VERSION_MINOR@.@KDAPI_VERSION_PATCH@
 * @brief A test source file of the MEM library.
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


#include "mem.h"
#include "gtest/gtest.h"

TEST(MemoryReallocationTest, BasicArguments)
{
  u8 *ptr, *dst;

  EXPECT_EQ(memRealloc(null, null, 0), MEM_FAILURE);
  EXPECT_EQ(memRealloc(null, null, -69), MEM_FAILURE);
  EXPECT_EQ(memRealloc(null, null, 64), MEM_FAILURE);
  EXPECT_EQ(memRealloc(null, &ptr, 0), MEM_FAILURE);
  EXPECT_EQ(memRealloc(null, &ptr, -420), MEM_FAILURE);
  EXPECT_EQ(memRealloc(null, &ptr, 128), MEM_FAILURE);

  dst = reinterpret_cast<u8*>(69);
  EXPECT_EQ(memRealloc(&dst, null, 0), MEM_FAILURE);
  EXPECT_EQ(dst, null);

  dst = reinterpret_cast<u8*>(69);
  EXPECT_EQ(memRealloc(&dst, null, -69), MEM_FAILURE);
  EXPECT_EQ(dst, null);

  dst = reinterpret_cast<u8*>(69);
  EXPECT_EQ(memRealloc(&dst, null, 64), MEM_FAILURE);
  EXPECT_EQ(dst, null);

  dst = reinterpret_cast<u8*>(69);
  EXPECT_EQ(memRealloc(&dst, &ptr, 0), MEM_FAILURE);
  EXPECT_EQ(dst, null);

  dst = reinterpret_cast<u8*>(69);
  EXPECT_EQ(memRealloc(&dst, &ptr, -420), MEM_FAILURE);
  EXPECT_EQ(dst, null);
}

TEST(MemoryReallocationTest, BasicAllocationBytes)
{
  u8 *ptr, *dst;

  EXPECT_EQ(memAlloc(&ptr, 1), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 64), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 64), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 128), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 512), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 256), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 512), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 512), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 64), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);
}

TEST(MemoryReallocationTest, BasicAllocationKiloBytes)
{
  u8 *ptr, *dst;

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 1), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 64), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 128), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 256), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 512), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 1024), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);
}

TEST(MemoryReallocationTest, BasicAllocationMegaBytes)
{
  u8 *ptr, *dst;

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 64), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 128), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 256), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 512), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  EXPECT_EQ(memRealloc(&dst, &ptr, 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  ASSERT_NE(dst, null);
  if (dst != null) free(dst);
}

TEST(MemoryReallocationTest, BasicMultipleSequentialReallocationsBytes)
{
  u8 *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6, *ptr7, *ptr8, *ptr9, *ptr10, *ptr11;
  u8 *dst1, *dst2, *dst3, *dst4, *dst5, *dst6, *dst7, *dst8, *dst9, *dst10, *dst11;

  EXPECT_EQ(memAlloc(&ptr1, 1), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst1, &ptr1, 64), MEM_SUCCESS);
  EXPECT_EQ(ptr1, null);
  ASSERT_NE(dst1, null);

  ptr1 = dst1;
  EXPECT_EQ(memRealloc(&dst1, &ptr1, 128), MEM_SUCCESS);
  EXPECT_EQ(ptr1, null);
  ASSERT_NE(dst1, null);

  EXPECT_EQ(memAlloc(&ptr2, 64), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst2, &ptr2, 128), MEM_SUCCESS);
  EXPECT_EQ(ptr2, null);
  ASSERT_NE(dst2, null);

  ptr2 = dst2;
  EXPECT_EQ(memRealloc(&dst2, &ptr2, 256), MEM_SUCCESS);
  EXPECT_EQ(ptr2, null);
  ASSERT_NE(dst2, null);

  EXPECT_EQ(memAlloc(&ptr3, 128), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst3, &ptr3, 256), MEM_SUCCESS);
  EXPECT_EQ(ptr3, null);
  ASSERT_NE(dst3, null);

  ptr3 = dst3;
  EXPECT_EQ(memRealloc(&dst3, &ptr3, 512), MEM_SUCCESS);
  EXPECT_EQ(ptr3, null);
  ASSERT_NE(dst3, null);

  EXPECT_EQ(memAlloc(&ptr4, 256), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst4, &ptr4, 512), MEM_SUCCESS);
  EXPECT_EQ(ptr4, null);
  ASSERT_NE(dst4, null);

  ptr4 = dst4;
  EXPECT_EQ(memRealloc(&dst4, &ptr4, 1024), MEM_SUCCESS);
  EXPECT_EQ(ptr4, null);
  ASSERT_NE(dst4, null);

  EXPECT_EQ(memAlloc(&ptr5, 512), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst5, &ptr5, 256), MEM_SUCCESS);
  EXPECT_EQ(ptr5, null);
  ASSERT_NE(dst5, null);

  ptr5 = dst5;
  EXPECT_EQ(memRealloc(&dst5, &ptr5, 128), MEM_SUCCESS);
  EXPECT_EQ(ptr5, null);
  ASSERT_NE(dst5, null);

  EXPECT_EQ(memAlloc(&ptr6, 1024), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst6, &ptr6, 512), MEM_SUCCESS);
  EXPECT_EQ(ptr6, null);
  ASSERT_NE(dst6, null);

  ptr6 = dst6;
  EXPECT_EQ(memRealloc(&dst6, &ptr6, 256), MEM_SUCCESS);
  EXPECT_EQ(ptr6, null);
  ASSERT_NE(dst6, null);

  EXPECT_EQ(memAlloc(&ptr7, 512), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst7, &ptr7, 256), MEM_SUCCESS);
  EXPECT_EQ(ptr7, null);
  ASSERT_NE(dst7, null);

  ptr7 = dst7;
  EXPECT_EQ(memRealloc(&dst7, &ptr7, 128), MEM_SUCCESS);
  EXPECT_EQ(ptr7, null);
  ASSERT_NE(dst7, null);

  EXPECT_EQ(memAlloc(&ptr8, 256), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst8, &ptr8, 128), MEM_SUCCESS);
  EXPECT_EQ(ptr8, null);
  ASSERT_NE(dst8, null);

  ptr8 = dst8;
  EXPECT_EQ(memRealloc(&dst8, &ptr8, 64), MEM_SUCCESS);
  EXPECT_EQ(ptr8, null);
  ASSERT_NE(dst8, null);

  EXPECT_EQ(memAlloc(&ptr9, 128), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst9, &ptr9, 64), MEM_SUCCESS);
  EXPECT_EQ(ptr9, null);
  ASSERT_NE(dst9, null);

  ptr9 = dst9;
  EXPECT_EQ(memRealloc(&dst9, &ptr9, 32), MEM_SUCCESS);
  EXPECT_EQ(ptr9, null);
  ASSERT_NE(dst9, null);

  EXPECT_EQ(memAlloc(&ptr10, 64), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst10, &ptr10, 32), MEM_SUCCESS);
  EXPECT_EQ(ptr10, null);
  ASSERT_NE(dst10, null);

  ptr10 = dst10;
  EXPECT_EQ(memRealloc(&dst10, &ptr10, 16), MEM_SUCCESS);
  EXPECT_EQ(ptr10, null);
  ASSERT_NE(dst10, null);

  EXPECT_EQ(memAlloc(&ptr11, 32), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst11, &ptr11, 16), MEM_SUCCESS);
  EXPECT_EQ(ptr11, null);
  ASSERT_NE(dst11, null);

  ptr11 = dst11;
  EXPECT_EQ(memRealloc(&dst11, &ptr11, 1), MEM_SUCCESS);
  EXPECT_EQ(ptr11, null);
  ASSERT_NE(dst11, null);

  if (dst1 != null) free(dst1);
  if (dst2 != null) free(dst2);
  if (dst3 != null) free(dst3);
  if (dst4 != null) free(dst4);
  if (dst5 != null) free(dst5);
  if (dst6 != null) free(dst6);
  if (dst7 != null) free(dst7);
  if (dst8 != null) free(dst8);
  if (dst9 != null) free(dst9);
  if (dst10 != null) free(dst10);
  if (dst11 != null) free(dst11);
}

TEST(MemoryReallocationTest, BasicMultipleSequentialReallocationsKiloBytes)
{
  u8 *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6, *ptr7, *ptr8, *ptr9, *ptr10, *ptr11;
  u8 *dst1, *dst2, *dst3, *dst4, *dst5, *dst6, *dst7, *dst8, *dst9, *dst10, *dst11;

  EXPECT_EQ(memAlloc(&ptr1, 1024 * 1), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst1, &ptr1, 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(ptr1, null);
  ASSERT_NE(dst1, null);

  ptr1 = dst1;
  EXPECT_EQ(memRealloc(&dst1, &ptr1, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr1, null);
  ASSERT_NE(dst1, null);

  EXPECT_EQ(memAlloc(&ptr2, 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst2, &ptr2, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr2, null);
  ASSERT_NE(dst2, null);

  ptr2 = dst2;
  EXPECT_EQ(memRealloc(&dst2, &ptr2, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr2, null);
  ASSERT_NE(dst2, null);

  EXPECT_EQ(memAlloc(&ptr3, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst3, &ptr3, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr3, null);
  ASSERT_NE(dst3, null);

  ptr3 = dst3;
  EXPECT_EQ(memRealloc(&dst3, &ptr3, 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(ptr3, null);
  ASSERT_NE(dst3, null);

  EXPECT_EQ(memAlloc(&ptr4, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst4, &ptr4, 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(ptr4, null);
  ASSERT_NE(dst4, null);

  ptr4 = dst4;
  EXPECT_EQ(memRealloc(&dst4, &ptr4, 1024 * 1024), MEM_SUCCESS);
  EXPECT_EQ(ptr4, null);
  ASSERT_NE(dst4, null);

  EXPECT_EQ(memAlloc(&ptr5, 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst5, &ptr5, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr5, null);
  ASSERT_NE(dst5, null);

  ptr5 = dst5;
  EXPECT_EQ(memRealloc(&dst5, &ptr5, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr5, null);
  ASSERT_NE(dst5, null);

  EXPECT_EQ(memAlloc(&ptr6, 1024 * 1024), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst6, &ptr6, 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(ptr6, null);
  ASSERT_NE(dst6, null);

  ptr6 = dst6;
  EXPECT_EQ(memRealloc(&dst6, &ptr6, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr6, null);
  ASSERT_NE(dst6, null);

  EXPECT_EQ(memAlloc(&ptr7, 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst7, &ptr7, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(ptr7, null);
  ASSERT_NE(dst7, null);

  ptr7 = dst7;
  EXPECT_EQ(memRealloc(&dst7, &ptr7, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr7, null);
  ASSERT_NE(dst7, null);

  EXPECT_EQ(memAlloc(&ptr8, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst8, &ptr8, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(ptr8, null);
  ASSERT_NE(dst8, null);

  ptr8 = dst8;
  EXPECT_EQ(memRealloc(&dst8, &ptr8, 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(ptr8, null);
  ASSERT_NE(dst8, null);

  EXPECT_EQ(memAlloc(&ptr9, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst9, &ptr9, 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(ptr9, null);
  ASSERT_NE(dst9, null);

  ptr9 = dst9;
  EXPECT_EQ(memRealloc(&dst9, &ptr9, 1024 * 32), MEM_SUCCESS);
  EXPECT_EQ(ptr9, null);
  ASSERT_NE(dst9, null);

  EXPECT_EQ(memAlloc(&ptr10, 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst10, &ptr10, 1024 * 32), MEM_SUCCESS);
  EXPECT_EQ(ptr10, null);
  ASSERT_NE(dst10, null);

  ptr10 = dst10;
  EXPECT_EQ(memRealloc(&dst10, &ptr10, 1024 * 16), MEM_SUCCESS);
  EXPECT_EQ(ptr10, null);
  ASSERT_NE(dst10, null);

  EXPECT_EQ(memAlloc(&ptr11, 1024 * 32), MEM_SUCCESS);
  EXPECT_EQ(memRealloc(&dst11, &ptr11, 1024 * 16), MEM_SUCCESS);
  EXPECT_EQ(ptr11, null);
  ASSERT_NE(dst11, null);

  ptr11 = dst11;
  EXPECT_EQ(memRealloc(&dst11, &ptr11, 1024 * 1), MEM_SUCCESS);
  EXPECT_EQ(ptr11, null);
  ASSERT_NE(dst11, null);

  if (dst1 != null) free(dst1);
  if (dst2 != null) free(dst2);
  if (dst3 != null) free(dst3);
  if (dst4 != null) free(dst4);
  if (dst5 != null) free(dst5);
  if (dst6 != null) free(dst6);
  if (dst7 != null) free(dst7);
  if (dst8 != null) free(dst8);
  if (dst9 != null) free(dst9);
  if (dst10 != null) free(dst10);
  if (dst11 != null) free(dst11);
}
