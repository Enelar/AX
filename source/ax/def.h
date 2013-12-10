/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_DEF_H_
#define _AX_DEF_H_

#if _DEBUG
//! @define Is library should be compiled in debug mode
#define _DEBUG_ 1
#else
#define _DEBUG_ 0
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL    nullptr
#else
#define NULL    ((void *)0)
#endif
#endif

#define QUOTEME(x) #x
#define TOSTRING(x) QUOTEME(x)

#ifndef WORD_SIZE
#define WORD_SIZE 4
#endif

#ifndef SLOW
#define SLOW
#endif

#ifndef DEPRECATED
#define DEPRECATED
#endif

#define REQUIRE_CPP11
#define REQUIRE_CPP14

#ifndef CPP11_SUPPORTED
#define CPP11_SUPPORTED (_MSC_VER >= 1800) /* VS2013 minimal */
#endif

#ifndef CPP14_SUPPORTED
#define CPP14_SUPPORTED 0
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

#define compile_error(message) static_assert(false, (message))

#define implementation_required(message) compile_error("Implementation required: " message)
#define IMPLEMENTATION_REQUIRED /*implementation_required("")*/ compile_error("Implementation required");


#include <stddef.h>
#include "base\assert.h"
#include "base\exceptions.h"
#include "base\types.h"
#include "base\utils.h"
#include "base\convert.h"

#endif