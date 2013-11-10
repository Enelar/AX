/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "stream_base.h"

using namespace ax::streams;

stream_base::stream_base( bool inited_by_default )
: Fail(false), End(false), Inited(inited_by_default)
{
}

inline bool stream_base::IsFail() const
{
  return Fail;
}

inline bool stream_base::IsEnd() const
{
  return End;
}

inline bool stream_base::IsInit() const
{
  return Inited;
}

inline void stream_base::ChangeFailFlag( bool status )
{
  if (!IsFail() && status)
  {
    Fail = status;
    OnFail();
  }
  else
    Fail = status;
}

inline void stream_base::ChangeEndFlag( bool status )
{
  if (!IsEnd() && status)
  {
    End = status;
    OnEnd();
  }
  else
    End = status;
}

inline void stream_base::ChangeInitedFlag( bool status )
{
  if (!IsInit())
  {
    if (status)
    {
      Inited = true;
      OnInit();
    }
  }
  else
    if (!status)
    {
      Inited = false;
      OnDeinit();
    }
}

inline void stream_base::OnFail()
{
}

inline void stream_base::OnEnd()
{
}

inline void stream_base::OnInit()
{
}

inline void stream_base::OnDeinit()
{
}