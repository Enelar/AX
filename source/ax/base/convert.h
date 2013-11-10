/* This file protected by faith_base_00 license
* No part of this file could be copyed or changed without Develop Project agreement
* No part of this file could be used or viewed without Develop Project agreement
*/

#ifndef _AX_CONVERT_H_
#define _AX_CONVERT_H_

namespace ax
{
  template<typename B, typename A>
  B convert(const A &a)
  {
    return static_cast<B>(a);
  }
}

#endif