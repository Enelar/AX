/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_ABSTRACT_PULL_H_
#define _AX_STREAM_ABSTRACT_PULL_H_

#include "iendpoint.h"
#include "..\..\structs\buffer.h"

namespace ax
{
  namespace streams
  {
    class abstract_pull : public oendpoint
    {
    public:
      virtual ax::mem::fast_mem Pull( ) = 0;
    };
  };
};

#endif