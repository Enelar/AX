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
#define NULL    0
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

#include <stddef.h>
#include "base\assert.h"
#include "base\exceptions.h"
#include "base\types.h"
#include "base\utils.h"

#endif