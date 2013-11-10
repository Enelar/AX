/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_MEM_BLOCK_H_
#define _AX_MEM_BLOCK_H_

namespace ax
{
  namespace mem
  {
    struct mem_block : public copyable
    {
      ub *mem;
      sst size;
      mem_block( ub *m, sst s );
      ~mem_block();
      ub *operator*( );
      ub &operator[]( sst a );
      ub *operator+( sst a );
      const ub *const operator*( ) const;
      const ub operator[]( sst a ) const;
      const ub *const operator+( sst a ) const;
      sst operator()( ) const;
      virtual copyable *Copy( void ) const;
    };
  };
};

#endif