/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_THREADS_THREAD_H_
#define _AX_THREADS_THREAD_H_

#include "talk.h"

namespace ax
{
  namespace threads
  {
    class thread : protected mutex
    {
      friend class thread_controller;
      bool in_other_thread;
    protected:
      talk from_owner, to_owner;
      void Sleep( uw ms );
      void WaitForWord( uw count = 1, uw recheck_ms = 1 );
    public:
      virtual ui function() = 0;
      void SetDone()
      {
        to_owner.SetDone();
      }
      bool GetDone()
      {
        return from_owner.GetDone();
      }
    public:
      thread() : in_other_thread(false)
      {
      }
      thread_controller *Start();
    };
    void Sleep( uw ms );
  }
}

#include "thread_controller.h"


#endif