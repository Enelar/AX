/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_CRYPT_H_
#define _AX_TL4_CRYPT_H_

#include "../../stream/stream_pump.h"

namespace ax
{
  namespace tl4
  {
    class crypt : public ax::streams::pipe
    {
    public:
      default_buffer Read( dword &readed, const dword count = 0);
      virtual default_buffer BeforeReturn( default_buffer &inc )
      {
        return inc;
      }
    protected:
      void SlowRead( ub *const &buffer, dword &readed, const dword count );
    };
  };
};

#endif