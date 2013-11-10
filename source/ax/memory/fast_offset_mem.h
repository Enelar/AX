/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_MEM_FAST_OFFSET_MEM_H_
#define _AX_MEM_FAST_OFFSET_MEM_H_

namespace ax
{
  namespace mem
  {
    class fast_offset_mem : public fast_mem
    {
      sst offset;
      fast_offset_mem( parent_block *const a, sst offset );
    public:
      fast_offset_mem( ub *memory, sst size, sst offset );
      const ub *const operator*( ) const;
      const ub operator[]( sst a ) const;
      const ub *const operator+( sst a ) const;
      const fast_offset_mem &operator+=( sst a );
      const fast_offset_mem &operator-=( sst a );
      sst operator()( ) const;
      virtual void IncreaseOffset( sst value );
      virtual void DecreaseOffset( sst value );
      virtual const sst GetOffset() const;
      virtual slow_mem *SlowDown() const;
      fast_offset_mem( const fast_mem &a, const sst offset );
      fast_offset_mem( const fast_offset_mem &a );
      virtual copyable *Copy( void ) const;
      ~fast_offset_mem();
    };
  };
};

#endif