/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_MEM_SLOW_MEMORY_H_
#define _AX_MEM_SLOW_MEMORY_H_

namespace ax
{
  namespace mem
  {
    class fast_mem;
    class slow_mem : public copyable
    {
      mem_block m;
      slow_mem( const slow_mem &a );
      void operator=( slow_mem &a );
    public:
      slow_mem( ub *memory, sst size );
      ub *operator*( );
      ub &operator[]( sst a );
      ub *operator+( sst a );
      sst operator()( ) const;
      fast_mem *Accelerate( ) const;
      virtual copyable *Copy( void ) const;
    };
  };
};

#endif