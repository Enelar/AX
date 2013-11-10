/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_THREADS_THREAD_CONTROLLER_H_
#define _AX_THREADS_THREAD_CONTROLLER_H_

#include "talk.h"

namespace ax
{
  namespace threads
  {
    class thread_controller : public object
    {
      mutex &m;
      talk &to_thread, &from_thread;
      friend class thread;
      int handle;
      thread_controller( thread &t, int h ) :
          m(t), to_thread(t.from_owner), from_thread(t.to_owner), handle(h)
      {
      }
    public:
      ~thread_controller()
      {
        to_thread.SetDone();
      }

      bool GetDone()
      {
        return from_thread.GetDone();
      }

      template<typename type>
      void Say( type word )
      {
        to_thread.Say(word);
      }

      void Say( ui *word, int count )
      {
        to_thread.Say(word, count);
      }

      ui Listen( )
      {
        return from_thread.Listen();
      }

      dword Count()
      {
        return from_thread.Count();
      }

      operator mutex &()
      {
        return m;
      }
    };
  }
}

#endif