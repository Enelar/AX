/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_THREADS_TALK_H_
#define _AX_THREADS_TALK_H_

#include "lock.h"
#include <list>

namespace ax
{
  namespace threads
  {
    class talk
    {
      std::list<ui> words;
      bool iamdone;
      mutex m;
    public:
      talk() : iamdone(false)
      {
      }
      void SetDone()
      {
        single_thread(m);
        iamdone = true;
      }
      bool GetDone()
      {
        single_thread(m);
        return iamdone;
      }

      template<typename type>
      void Say( type word )
      {
        throw_assert(sizeof(type) == sizeof(ui));
        ui said = CAST(word, ui);
        single_thread(m);
        words.push_back(said);
      }

      void Say( ui *word, int count )
      {
        single_thread(m);
        for (int i = 0; i < count; i++)
          words.push_back(word[i]);
      }

      ui Listen( )
      {
        single_thread(m);
        int ret = words.front();
        words.pop_front();
        return ret;
      }

      dword Count()
      {
        single_thread(m);
        return words.size();
      }
    };
  }
}

#endif