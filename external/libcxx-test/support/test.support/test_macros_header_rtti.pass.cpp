/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: libcpp-no-rtti

// "support/test_macros.hpp"

// #define TEST_HAS_NO_RTTI

#include "test_macros.h"

#if defined(TEST_HAS_NO_RTTI)
#error Macro defined unexpectedly
#endif

struct A { virtual ~A() {} };
struct B : A {};

int main() {
    A* ptr = new B;
    (void)dynamic_cast<B*>(ptr);
    delete ptr;
}
