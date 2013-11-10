/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "iendpoint.h"

using namespace ax::streams;

iendpoint::iendpoint( bool can_write_default, bool inited_by_default )
: stream_base(inited_by_default), CanWrite(can_write_default)
{
}

inline bool iendpoint::IsCanWrite() const
{
  return CanWrite;
}

inline void iendpoint::ChangeWriteFlag( bool status )
{
  if (!IsCanWrite())
  {
    if (status)
    {
      CanWrite = true;
      OnWriteEnabled();
    }
  }
  else
    if (!status)
    {
      CanWrite = false;
      OnWriteDisabled();
    }
}


inline void iendpoint::OnWriteEnabled()
{
}
inline void iendpoint::OnWriteDisabled()
{
}
