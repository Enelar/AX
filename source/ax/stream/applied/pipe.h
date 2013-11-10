/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAMS_PIPE_H_
#define _AX_STREAMS_PIPE_H_

#include "pipe_constructor.h"

namespace ax
{
  namespace streams
  {
    class pipe : public abstract_duct
    {
      pipe( pipe_contructor &a );

      virtual void Push( ax::mem::fast_mem ) = 0;
      virtual ax::mem::fast_mem Pull() = 0;
      virtual dword GetBufferedSize() const SLOW;
      virtual dword CanAccept() const;
      virtual dword GetReadyOutputSize() const;

      virtual abstract_duct *CopyScheme() const = 0;
    private:
      virtual dword FreeSpace() const;
      std::list<abstract_duct *> ducts;
    };
  };
};

#endif