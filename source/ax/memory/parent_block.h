/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_MEM_PARENT_BLOCK_H_
#define _AX_MEM_PARENT_BLOCK_H_

#include "mem_block.h"

namespace ax
{
  namespace mem
  {
    class parent_block : protected shared_self_controlled
    {
      mem_block a;
    public:
      parent_block( ub *m, sst s );
      const mem_block &AddUser( );
      void RemoveUser( );
      ~parent_block();
    };
  };
};

#endif