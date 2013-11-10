/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_ABSTRACT_DUCT_H_
#define _AX_STREAM_ABSTRACT_DUCT_H_

#include "abstract_push.h"
#include "abstract_pull.h"

namespace ax
{
  namespace streams
  {
    class abstract_duct : public abstract_push, public abstract_pull
    {
    public:
      virtual void Push( ax::mem::fast_mem ) = 0;
      virtual ax::mem::fast_mem Pull() = 0;
      virtual dword GetBufferedSize() const SLOW;
      virtual dword FreeSpace() const;
      virtual dword GetReadyOutputSize() const;

      virtual abstract_duct *CopyScheme() const;
    };
  };
};

#endif