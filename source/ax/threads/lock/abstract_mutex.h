/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_THREADS_ABSTRACT_MUTEX_H_
#define _AX_THREADS_ABSTRACT_MUTEX_H_

#include "../../def.h"

namespace ax
{
  namespace threads
  {
    class abstract_mutex : public object
    {
    public:
      virtual void lock() = 0;
      virtual void unlock() = 0;
    };
  }
}

#endif