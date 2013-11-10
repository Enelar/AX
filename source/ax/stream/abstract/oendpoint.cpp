/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "oendpoint.h"

using namespace ax::streams;

oendpoint::oendpoint( bool can_read_default, bool inited_by_default )
: stream_base(inited_by_default), CanRead(can_read_default)
{
}

inline bool oendpoint::IsCanRead() const
{
  return CanRead;
}

inline void oendpoint::ChangeReadFlag( bool status )
{
  if (!IsCanRead())
  {
    if (status)
    {
      CanRead = true;
      OnReadEnabled();
    }
  }
  else
    if (!status)
    {
      CanRead = false;
      OnReadDisabled();
    }
}

inline void oendpoint::OnReadEnabled()
{
}

inline void oendpoint::OnReadDisabled()
{
}