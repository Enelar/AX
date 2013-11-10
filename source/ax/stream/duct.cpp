/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "duct.h"

using namespace ax::streams;

inline void duct::Push( ax::mem::fast_mem mem )
{
  buf.Push(mem);
}

inline ax::mem::fast_mem duct::Pull()
{
  return buf.Pop();
}

inline dword duct::GetBufferedSize() const
{
  return buf.GetBufferSize();
}

inline dword duct::FreeSpace() const
{
  if (!buf.RemainFragments())
    return 0;
  return buf.FreeSpace();
}
