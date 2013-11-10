/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_DUCT_H_
#define _AX_STREAM_DUCT_H_

#include "abstract_push.h"

namespace ax
{
  namespace streams
  {
    class push : public abstract_push
    {
    protected:
      buffer buf;
    public:

      virtual void Push( ax::mem::fast_mem );
      virtual void Push( unsafe_byte *, dword size );
      virtual void PushString( char *, dword len );

    };
  };
};

#endif