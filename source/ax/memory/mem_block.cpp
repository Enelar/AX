/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "mem.h"

using namespace ax::mem;

mem_block::mem_block( ub *m, sst s ) : mem(m), size(s)
{
}
mem_block::~mem_block()
{
  delete []mem;
}

const ub *const mem_block::operator*( ) const
{
  return mem;
}

const ub mem_block::operator[]( sst a ) const
{
  return mem[a];
}

const ub *const mem_block::operator+( sst a ) const
{
  return mem + a;
}

ub *mem_block::operator*( )
{
  return mem;
}

ub &mem_block::operator[]( sst a )
{
  return mem[a];
}

ub *mem_block::operator+( sst a )
{
  return mem + a;
}

sst mem_block::operator()( ) const
{
  return size;
}

ax::copyable *mem_block::Copy( ) const
{
  ub *to_export = NEW ub[size];
  MemCpy(to_export, mem, size);
  return NEW mem_block(to_export, size);
}