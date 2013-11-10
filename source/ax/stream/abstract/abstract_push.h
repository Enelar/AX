/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_ABSTRACT_PUSH_H_
#define _AX_STREAM_ABSTRACT_PUSH_H_

#include "oendpoint.h"
#include "..\..\structs\buffer.h"

namespace ax
{
  namespace streams
  {
    class abstract_push : public oendpoint
    {
    public:
      virtual void Push( ax::mem::fast_mem ) = 0;
      virtual void Push( unsafe_byte *, dword size );
    };
  };
};

#endif