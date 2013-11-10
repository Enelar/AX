/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "timestamp.h"
#include <time.h>

#define CLOCKS_PER_SECOND ((dword)(CLOCKS_PER_SEC))
#define COUNT_START_POINT ((dword)(1309402800))

using namespace ax::units;

void real_timestamp::Init( const dword s, const dword m )
{
  ms = m;
  sec = s;
}

void real_timestamp::GetCurrent( void )
{
  Init(0, clock());
}

real_timestamp::real_timestamp( void )
{
  GetCurrent();
}

real_timestamp::real_timestamp( const real_timestamp &a )
{
  Init(a.sec, a.ms);
}

real_timestamp::operator dbl() const
{
  return sec + ms * 0.001;
}

real_timestamp &real_timestamp::operator=( const real_timestamp &t )
{
  ms = t.ms;
  sec = t.sec;
  return *this;
}

real_timestamp &timestamp::operator=( const real_timestamp &t )
{
  real_timestamp::operator =(t);
  is_real = true;
  return *this;
}

timestamp &timestamp::operator=( const timestamp &t )
{
  real_timestamp::operator =(t);
  is_real = t.is_real;
  return *this;
}


timestamp::timestamp( const timestamp &t ) : real_timestamp(t), is_real(t.is_real)
{
}
timestamp::timestamp( const real_timestamp &t ) : real_timestamp(t), is_real(true)
{
}

bool timestamp::IsReal() const
{
  return is_real;
}

timestamp::timestamp() : real_timestamp(), is_real(false)
{
}
