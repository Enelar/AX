/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "toggle.h"

using namespace ax::units;

toggle::toggle( bool init ) : state(init)
{

}

bool toggle::Next()
{
  return state = !state;
}

bool toggle::State() const
{
  return state;
}

bool toggle::TurnFalse()
{
  if (!state)
    return false;
  state = false;
  return true;
}

bool toggle::TurnTrue()
{
  if (state)
    return false;
  return state = true;
}

toggle::operator bool &()
{
  return state;
}

toggle::operator bool() const
{
  return state;
}

bool toggle::IsChanged( const toggle &a ) const
{
  return state != a;
}

bool toggle::Update( const toggle &a )
{
  if (!IsChanged(a))
    return false;
  state = a;
  return true;
}
