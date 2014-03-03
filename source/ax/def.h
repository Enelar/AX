/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#pragma once
#ifndef _AX_DEF_H_
#define _AX_DEF_H_

#include "base\pragma_once_test.h"

#if _DEBUG
//! @define Is library should be compiled in debug mode
#define _DEBUG_ 1
#else
#define _DEBUG_ 0
#endif

#ifndef __cplusplus
#error C++03 is required to build this library
#endif

#define QUOTEME(x) #x
#define TOSTRING(x) QUOTEME(x)

#ifndef WORD_SIZE
#define WORD_SIZE 4
#endif

#define SLOW
#define DEPRECATED
#define deprecated_method(name) __declspec(deprecated(TOSTRING(name))) name
#define MEMLEAK
#define REFACTOR
#define MAYBEWRONG
#define BEW MAYBEWRONG

#ifndef NULL
/* Please use nullptr directly */
#define NULL    DEPRECATED nullptr
#endif


#define REQUIRE_CPP11
#define REQUIRE_CPP14

#ifndef CPP11_SUPPORTED
#define CPP11_SUPPORTED (__cplusplus >= 201103L)
#endif

#ifndef CPP14_SUPPORTED
#define CPP14_SUPPORTED (__cplusplus >= 201400L)
#endif

#if CPP11_SUPPORTED
#define CPP11_ONLY(code) code
#else
#define CPP11_ONLY(code)
#endif

#if CPP14_SUPPORTED
#define CPP14_ONLY(code) code
#else
#define CPP14_ONLY(code)
#endif

#define compile_error(message) static_assert(false, message)

#define implementation_required(message) compile_error("Implementation required: " message)
#define IMPLEMENTATION_REQUIRED /*implementation_required("")*/ compile_error("Implementation required");

#ifndef DEPRECATED_ERRORS_IGNORE
#define DEPRECATED_ERRORS_IGNORE 0
#endif

#define DEPRECATED_FORCE static_assert(DEPRECATED_ERRORS_IGNORE, "This code is deprecated. It will removed in futute. Use DEPRECATED_ERRORS_IGNORE to workaround");

#include <stddef.h>
#include "base\assert.h"
#include "base\exceptions.h"
#include "base\types.h"
#include "base\utils.h"
#include "base\convert.h"

#endif