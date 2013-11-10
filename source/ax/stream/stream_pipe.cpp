/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "stream_pipe.h"

using namespace ax;
using namespace ax::streams;

word pipe::Avaible( void ) const
{
  return buffered + (in ? in->Avaible() : 0);
}

word pipe::Pos( void ) const
{
  return pos + (in ? in->Pos() : 0);
}

word pipe::Size( void ) const
{
  return size + (in ? in->Size() : 0);
}

stream::default_buffer pipe::Read( word &readed, const word count )
{
  word size = Min(count, Avaible()), completed = 0;
  ub *to_export = NEW ub[size];
  SlowRead(to_export, readed, size);
  throw_assert(readed == size);
  return default_buffer(to_export, size, 0);
}

void pipe::SlowRead( ub *const &buf, word &readed, const word count )
{
  throw_assert(can_read);
  throw_assert(count <= Avaible());
  word completed = 0, size = buffer.size();
  while (completed < count && size)
  {
    default_buffer &t = buffer.front();
    sst read = Min(count - completed, t());
    throw_assert(read);
    MemCpy(buf + completed, *t, read);
    t.IncreaseOffset(read);
    if (!t())
      buffer.pop_front();
    completed += read;
  }
  readed = completed;
  if (completed >= count)
    return;
  throw_assert(in);
  in->SlowRead(buf + completed, size, count - completed);
  readed += size;
}

void pipe::Add( ub *&buf, const word size )
{
  throw_assert(can_write);
  default_buffer b(buf, size, 0);
  buffer.push_back(b);
}
void pipe::Fill( const ub *const b, const word size )
{
  ub *to_insert = NEW ub[size];
  MemCpy(to_insert, b, size);
  Add(to_insert, size);
}
void pipe::End( )
{
  can_write = false;
}