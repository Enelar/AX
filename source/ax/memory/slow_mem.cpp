/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "mem.h"

using namespace ax::mem;

slow_mem::slow_mem( ub *memory, sst size ) : m(memory, size)
{

}
ub *slow_mem::operator*( )
{
  return *m;
}
ub &slow_mem::operator[]( sst a )
{
  return m[a];
}
ub *slow_mem::operator+( sst a )
{
  return m + a;
}
sst slow_mem::operator()( ) const
{
  return m();
}
fast_mem *slow_mem::Accelerate( ) const
{
  slow_mem *t = SER(Copy(), slow_mem);
  fast_mem *ret = NEW fast_mem(**t, (*t)());
  t->m.mem = NULL;
  delete t;
  return ret;
}

ax::copyable *slow_mem::Copy( void ) const
{
  sst size = (*this)();
  ub *to_export = NEW ub[size];
  MemCpy(to_export, *m, size);
  return NEW slow_mem(to_export, size);
}