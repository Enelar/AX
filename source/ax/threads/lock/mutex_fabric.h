/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_THREADS_MUTEX_FABRIC_H_
#define _AX_THREADS_MUTEX_FABRIC_H_

#include "abstract_mutex.h"
#include "../../structs/singletone.h"

namespace ax
{
  namespace threads
  {
    class mutex_fabric
    {
    public:
      static abstract_mutex *CreateDefault();
    };
  }
  namespace structs
  {
    template<>
    ax::threads::abstract_mutex *InitSingletone();
  }
}

#endif