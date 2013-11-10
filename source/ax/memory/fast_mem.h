/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_MEM_FAST_MEM_H_
#define _AX_MEM_FAST_MEM_H_

namespace ax
{
  namespace mem
  {
    class slow_mem;
    class fast_mem : public copyable
    {
    protected:
      parent_block *const p;
      const mem_block &m;
      fast_mem( parent_block *const a );
    public:
      fast_mem( ub *memory, sst size );
      const ub *const operator*( ) const;
      const ub operator[]( sst a ) const;
      const ub *const operator+( sst a ) const;
      sst operator()( ) const;
      virtual slow_mem *SlowDown() const;
      fast_mem( const fast_mem &a );
      virtual copyable *Copy( void ) const;
      ~fast_mem();
    };
  };
};

#endif