/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_THREADS_LOCK_H_
#define _AX_THREADS_LOCK_H_

#include "lock/mutex.h"

namespace ax
{
  namespace threads
  {
    class lock
    {
      bool locked;
      mutex &obj;
    public:
      lock( mutex *const m ) : obj(*m), locked(true)
      {
        throw_assert(m); // later but need
      }
      lock( mutex &m ) : obj(m), locked(true)
      {
        obj.lock();
      }
      ~lock()
      {
        obj.unlock();
      }
      operator bool() const
      {
        return locked;
      }
      void DeSynchronize()
      {
        locked = false;
      }
    };
  }
}

#define synchronized(M) for (ax::threads::lock M##_lock = M; M##_lock; M##_lock.DeSynchronize())
#define single_thread(M) lock M##_lock = M;

#endif