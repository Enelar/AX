/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_BUFFER_H_
#define _AX_STREAM_BUFFER_H_

#include "../memory/mem.h"
#include <list>

namespace ax
{
  namespace structs
  {
    class buffer
    {
    protected:
      typedef ax::mem::fast_mem fast_mem;
      typedef ax::mem::slow_mem slow_mem;
      std::list<fast_mem> store;
      const dword max_size, max_fragments;
      dword size;
    public:
      buffer( dword MaxSize, dword MaxFragments );
      ~buffer();

      void Push( fast_mem mem );
      void Push( fast_mem mem, dword size );
      fast_mem Pop();
      fast_mem Pop( dword size ) SLOW;

      dword GetCurrentCapacity() const;
      dword GetCurrentFragments() const;
      void Defragment() SLOW;
      void DefragmentBegin( dword fragments );
      void DefragmentEnd( dword fragments );

      dword GetFirstSegmentSize() const;
      dword GetBufferSize() const;
      dword RemainFragments() const;
      dword FreeSpace() const;

      void SetReverseMode( bool status );
    private:
      bool IsReverseMode;

    private:
      void Raw_ForwardPush( fast_mem mem );
      void Raw_ForwardPush( fast_mem mem, dword size );
      fast_mem Raw_ForwardPop();
      fast_mem Raw_ForwardPop( dword size );

      void Raw_BackwardPush( fast_mem mem );
      void Raw_BackwardPush( fast_mem mem, dword size );
      fast_mem Raw_BackwardPop();
      fast_mem Raw_BackwardPop( dword size );
    };
  };
};

#endif