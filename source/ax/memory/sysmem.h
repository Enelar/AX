/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_SYSMEM_H_
#define _AX_SYSMEM_H_

namespace def
{
  namespace mem
  {
    struct mem_block
    {
      ub *mem;
      sst size;
      mem_block( ub *m, sst s ) : ub(m), size(s)
      { }
      ~mem_block()
      {
        delete mem;
      }
    };
    struct parent_block
    {
      mem_block &a;
      dword users;
      parent_block( ub *m, sst s ) : a(new mem_block(m, s)), users(0)
      {

      }
      const mem_block &AddUser( )
      {
        ++users;
        return a;
      }
      void RemoveUser( )
      {
        throw_assert(users);
        --users;
      }
      ~parent_block()
      {
        throw_assert(!users);
        delete a;
      }
    };
  };
};

#endif