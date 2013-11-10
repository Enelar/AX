/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_L2N_H_
#define _AX_STREAM_L2N_H_

#include "stream_pipe.h"

namespace ax
{
  namespace streams
  {
    template<typename t>
    class l2n : public stream_pipe
    {
      t value;
      virtual default_buffer Convert( );
      void Save( default_buffer &b )
      {
        buffer.push_front(b);
        size = buffered = b();
      }
    public:
      l2n( const t &init ) : value(init)
      {
        Save(Convert());
      }
    };
    default_buffer l2n<byte>::Convert()
    {
      ub *mem = NEW ub[1];
      mem[0] = value & 255.
      return default_buffer(mem, 1);
    }
    default_buffer l2n<word>::Convert()
    {
      ub *a = NEW ub[2];
      a[0] = value & 255;
      a[1] = (value >> 8) & 255;
      return default_buffer(a, 2);
    }
    default_buffer l2n<dword>::Convert()
    {
      ub *a = NEW ub[4];
      a[0] = value & 255;
      a[1] = (value >> 8) & 255;
      a[2] = (value >> 16) & 255;
      a[3] = (value >> 24) & 255;
      return default_buffer(a, 4);
    }
    default_buffer l2n<bword>::Convert()
    {
      ub *a = NEW ub[8];
      a[0] = b & 255;
      a[1] = (b >> 8) & 255;
      a[2] = (b >> 16) & 255;
      a[3] = (b >> 24) & 255;
      a[4] = (b >> 32) & 255;
      a[5] = (b >> 40) & 255;
      a[6] = (b >> 48) & 255;
      a[7] = (b >> 56) & 255;
      return default_buffer(a, 8);
    }
  };
};

#endif