/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "mem_sys.h"

using namespace ax::mem;

parent_block::parent_block( ub *m, sst s ) : a(m, s)
{

}
const mem_block &parent_block::AddUser( )
{
  shared_self_controlled::AddShare();
  return a;
}
void parent_block::RemoveUser( )
{
  shared_self_controlled::RemoveShare();
}
parent_block::~parent_block()
{
  throw_assert(!users);
}
