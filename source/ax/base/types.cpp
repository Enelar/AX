/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "../def.h"

using namespace ax;

#pragma warning(disable: 4245) // signed/unsigned mismatch
void ax::CheckTypes( void )
{
  static cifra checked = 0;

  if (checked)
    return;

  static_assert(WORD_SIZE == 4, "Wrong WORD_SIZE directive");
  static_assert(sizeof(unsafe_byte) == 1, "Wrong byte size " TOSTRING(sizeof(unsafe_byte)) " expect 1");
  static_assert(sizeof(unsafe_hword) == WORD_SIZE / 2, "Wrong hword size: " TOSTRING(sizeof(unsafe_hword)) " expect half of WORD_SIZE");
  static_assert(sizeof(unsafe_word) == WORD_SIZE, "Wrong word size: " TOSTRING(sizeof(unsafe_word)) " expect equal to WORD_SIZE");
  static_assert(sizeof(unsafe_dword) == WORD_SIZE * 2, "Wrong dword size: " TOSTRING(sizeof(unsafe_dword)) " expect twice of WORD_SIZE");
  static_assert(sizeof(unsafe_bword) >= WORD_SIZE * 2, "Wrong bword size: " TOSTRING(sizeof(unsafe_bword)) " expect minimal twice of WORD_SIZE");

  unsafe_byte ub = -1;
  byte b = ub;
  throw_sassert(b == BYTE_MAX, "Wrong max byte value! Unbelievable! Its impossible!");

  unsafe_hword uhw = -1;
  hword hw = uhw;
  throw_sassert(hw == HWORD_MAX, "Wrong max word value! Unbelievable! Its impossible!");

  unsafe_word uw = -1;
  word w = uw;
  throw_sassert(w == WORD_MAX, "Wrong max word value! Unbelievable! Its impossible!");

  unsafe_dword udw = -1;
  dword dw = udw;
  throw_sassert(dw == DWORD_MAX, "Wrong max dword value! Unbelievable! Its impossible!");

  unsafe_bword ubw = -1;
  bword bw = ubw;
  throw_sassert(bw == BWORD_MAX, "Wrong max bword value! Unbelievable! Its impossible!");

  unsafe_int ui = ~0; // should test
  cifra i = ui;
  throw_sassert(i == CIFRA_MAX, "Wrong max cifra value! Unbelievable! Its impossible!");

  unsafe_bigint ubi = ~0; // should test
  bigint bi = ubi;
  throw_sassert(bi == BIGINT_MAX, "Wrong max bigint value! Unbelievable! Its impossible!");

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
