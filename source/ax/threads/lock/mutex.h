/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_THREADS_MUTEX_H_
#define _AX_THREADS_MUTEX_H_

#include "mutex_fabric.h"
#include "abstract_mutex.h"
#include "../structs/singletone.h"

namespace ax
{
  namespace threads
  {
    class mutex : public object
    {
    public:
      typedef structs::singletone<abstract_mutex> container;
      container m;
    public:
      mutex( abstract_mutex *a = NULL ) : m(a)
      {
        lock(), unlock();
      }
      void lock()
      {
        m->lock();
      }
      void unlock()
      {
        m->unlock();
      }
    };
  }
}

#endif