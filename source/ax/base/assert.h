/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_ASSERT_H_
#define _AX_ASSERT_H_

#ifndef _AX_DEF_H_
#error AX: Wrong assert.h include
#endif

namespace ax
{
  static bool memleak_debug_enabled = false;
};


// Memory leaks detection
#ifndef _MEMLEAK_DETECT_ENABLED
  #define _AX_DETECT_MEMORY_LEAKS_
  #define _MEMLEAK_DETECT_ENABLED
  #if _DEBUG_
    #define _CRTDBG_MAP_ALLOC
    #include <crtdbg.h>
    #include <assert.h>
    #define NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
    #define BREAK_ON_MEMORY_LEAK(x) _CrtSetBreakAlloc(x)

    static class dbgMEMORY {
    public:
      dbgMEMORY()
      {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF    | _CRTDBG_LEAK_CHECK_DF |
                       _CRTDBG_CHECK_ALWAYS_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG));
        ax::memleak_debug_enabled = true;
      }
    } _MEMORY;
  #else
    #define BREAK_ON_MEMORY_LEAK(x) 
    #define NEW new
  #endif // _DEBUG_
#endif // MEMLEAK_DETECT_ENABLE

#if _DEBUG_
#define BREAK_ON_MEMORY_LEAK(x) _CrtSetBreakAlloc(x)
#else

#endif

#endif