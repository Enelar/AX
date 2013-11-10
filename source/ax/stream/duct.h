/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_DUCT_H_
#define _AX_STREAM_DUCT_H_

#include "abstract\abstract_duct.h"
#include "..\structs\buffer.h"


namespace ax
{
  namespace streams
  {
    class duct : public abstract_duct
    {
    protected:
      ax::structs::buffer buf;
    public:
      virtual void Push( ax::mem::fast_mem );
      virtual ax::mem::fast_mem Pull();
      virtual dword GetBufferedSize() const;
      virtual dword FreeSpace() const;
    };
  };
};

#endif