/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "../def.h"

using namespace ax;

void ax::CheckTypes( void )
{
  static cifra checked = 0;

  if (checked)
    return;
  throw_sassert(sizeof(unsafe_byte) == 1, "Wrong byte size " TOSTRING(sizeof(unsafe_byte)) " expect 1");
  throw_sassert(sizeof(unsafe_word) == 2, "Wrong word size: " TOSTRING(sizeof(unsafe_word)) " expect 2");
  throw_sassert(sizeof(unsafe_dword) == 4, "Wrong dword size: " TOSTRING(sizeof(unsafe_dword)) " expect 4");
  throw_sassert(sizeof(unsafe_bword) == 8, "Wrong bword size: " TOSTRING(sizeof(unsafe_bword)) " expect 8");

  unsafe_byte ub = -1;
  byte b = ub;
  throw_sassert(b == BYTE_MAX, "Wrong max byte value! Unbelievable! Its impossible!");

  unsafe_word uw = -1;
  word w = uw;
  throw_sassert(w == WORD_MAX, "Wrong max word value! Unbelievable! Its impossible!");

  unsafe_dword udw = -1;
  dword dw = udw;
  throw_sassert(dw == DWORD_MAX, "Wrong max dword value! Unbelievable! Its impossible!");

  unsafe_bword ubw = -1;
  bword bw = ubw;
  throw_sassert(bw == BWORD_MAX, "Wrong max bword value! Unbelievable! Its impossible!");

  checked = 1;
}

shared::shared() : users(0)
{
}
void shared::AddShare( )
{
  ++users;
}
void shared::RemoveShare( )
{
  throw_assert(users);
  --users;
}
shared::~shared()
{
  throw_assert(!users);
}
void shared_self_controlled::RemoveShare( )
{
  shared::RemoveShare();
  if (!users)
    delete this;
}
