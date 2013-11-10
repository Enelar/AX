/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "mem.h"

using namespace ax::mem;

fast_mem::fast_mem( ub *memory, sst size ) : p(NEW parent_block(memory, size)), m(p->AddUser())
{
}
const ub *const fast_mem::operator*( ) const
{
  return *m;
}
const ub fast_mem::operator[]( sst a ) const
{
  return m[a];
}
const ub *const fast_mem::operator+( sst a ) const
{
  return m + a;
}
sst fast_mem::operator()( ) const
{
  return m();
}
slow_mem *fast_mem::SlowDown() const
{
  mem_block *t = SER(m.Copy(), mem_block);
  slow_mem *ret = NEW slow_mem(t->mem, t->size);
  t->mem = NULL;
  delete t;
  return ret;
}

fast_mem::fast_mem( const fast_mem &a ) : p(a.p), m(a.p->AddUser())
{
}

fast_mem::fast_mem( parent_block *const a ) : p(a), m(a->AddUser())
{
}

fast_mem::~fast_mem()
{
  p->RemoveUser();
}
ax::copyable *fast_mem::Copy( void ) const
{
  return NEW fast_mem(*this);
}