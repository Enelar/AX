/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "buffer.h"

using namespace ax::structs;

buffer::buffer( dword MaxSize, dword MaxFragments = DWORD_MAX )
: max_size(MaxSize), max_fragments(MaxFragments), size(0)
{
}

void buffer::Push( buffer::fast_mem mem )
{
  if (IsReverseMode)
    Raw_BackwardPush(mem);
  else
    Raw_ForwardPush(mem);
}

void buffer::Push( buffer::fast_mem mem, dword size )
{
  if (IsReverseMode)
    Raw_BackwardPush(mem, size);
  else
    Raw_ForwardPush(mem, size);
}

buffer::fast_mem buffer::Pop()
{
  if (IsReverseMode)
    return Raw_BackwardPop();
  else
    return Raw_ForwardPop();
}

buffer::fast_mem buffer::Pop( dword size )
{
  if (IsReverseMode)
    return Raw_BackwardPop(size);
  else
    return Raw_ForwardPop(size);
}

void buffer::SetReverseMode( bool status )
{
  IsReverseMode = status;
}

dword buffer::GetBufferSize() const
{
  return size;
}

dword buffer::GetCurrentFragments() const
{
  return store.size();
}

buffer::~buffer()
{
}


