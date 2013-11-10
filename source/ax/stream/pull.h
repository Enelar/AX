/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAMS_PULL_H_
#define _AX_STREAMS_PULL_H_

#include "abstract_pull.h"
#include "buffer.h"

namespace ax
{
  namespace streams
  {
    class pull : public abstract_pull
    {
    protected:
      buffer buf;
    public:
      virtual ax::mem::fast_mem Pull( );
    };
  };
};

#endif