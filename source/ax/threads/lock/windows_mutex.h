/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_THREADS_WINDOWS_MUTEX_H_
#define _AX_THREADS_WINDOWS_MUTEX_H_

#include "abstract_mutex.h"
#include "../../structs/singletone.h"
#include <windows.h>

namespace ax
{
  namespace threads
  {
    class windows_mutex : public abstract_mutex
    {
      ax::structs::singletone<CRITICAL_SECTION> sect;
    public:
      windows_mutex()
      {
        sect();
      }
      virtual void lock()
      {
        EnterCriticalSection(sect());
      }
      virtual void unlock()
      {
        LeaveCriticalSection(sect());
      }
    };
  }
  namespace structs
  {
    template<>
    CRITICAL_SECTION *InitSingletone()
    {
      CRITICAL_SECTION *ret = NEW CRITICAL_SECTION;
      InitializeCriticalSection(ret);
      return ret;
    }
    template<>
    void DeInitSingletone( CRITICAL_SECTION *a )
    {
      DeleteCriticalSection(a);
    }
  }
}

#endif

