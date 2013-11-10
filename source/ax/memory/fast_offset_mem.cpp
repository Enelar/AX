/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "mem.h"

using namespace ax::mem;

fast_offset_mem::fast_offset_mem( parent_block *const a, sst of ) : fast_mem(a), offset(of)
{

}
fast_offset_mem::fast_offset_mem( ub *memory, sst size, sst of ) : fast_mem(memory, size), offset(of)
{
}
const ub *const fast_offset_mem::operator*( ) const
{
  return *m + offset;
}
const ub fast_offset_mem::operator[]( sst a ) const
{
  return (m + offset)[a];
}
const ub *const fast_offset_mem::operator+( sst a ) const
{
  return m + offset + a;
}
const fast_offset_mem &fast_offset_mem::operator+=( sst a )
{
  offset += a;
  throw_assert(offset < m());
  return *this;
}
const fast_offset_mem &fast_offset_mem::operator-=( sst a )
{
  offset -= a;
  return *this;
}
sst fast_offset_mem::operator()( ) const
{
  return m() - offset;
}
void fast_offset_mem::IncreaseOffset( sst value )
{
  throw_assert(offset + value < (*this)());
  offset += value;
}
void fast_offset_mem::DecreaseOffset( sst value )
{
  throw_assert(offset >= value);
  offset -= value;
}

const sst fast_offset_mem::GetOffset() const
{
  return offset;
}
slow_mem *fast_offset_mem::SlowDown() const
{
  sst size = (*this)();
  ub *to_export = NEW ub[size];
  MemCpy(to_export, **this, size);
  return NEW slow_mem(to_export, size);
}
fast_offset_mem::fast_offset_mem( const fast_mem &a, const sst of ) : fast_mem(a), offset(of)
{

}
fast_offset_mem::fast_offset_mem( const fast_offset_mem &a ) : fast_mem(a), offset(a.offset)
{

}
ax::copyable *fast_offset_mem::Copy( void ) const
{
  return NEW fast_offset_mem(*this);
}
fast_offset_mem::~fast_offset_mem()
{
}