/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "stream.h"

using namespace ax;
using namespace ax::streams;

void stream::Default()
{
  destroy_by_out = destroy_by_in = false;
  out = in = NULL;
  can_read = can_write = false;
}

stream::stream()
{
  Default();
}

stream::stream( stream *const source ) 
{
  throw_assert(source);
  Default();
  can_read = source->can_read;
  can_write = source->can_write;
  Attach(source);
}

stream::~stream( void )
{
  if (out)
    out->DeAttach(this);
  if (in)
  {
    throw_assert(!destroy_by_in); // check next
    //destroy_by_in = false;
    DeAttach(in);
  }
}

word stream::Avaible( void ) const
{
  if (in)
    return in->Avaible();
  todo(stream::Avaible. mode out);
}

word stream::Pos( void ) const
{
  if (in)
    return in->Pos();
  todo(stream::Avaible. mode out);
}

word stream::Size( void ) const
{
  if (in)
    return in->Size();
  todo(stream::Avaible. mode out);
}

bool stream::IsBegin( void ) const
{
  return !Pos();
}

bool stream::IsEnd( void ) const
{
  return Pos() == Size();
}

bool stream::Finished( void ) const
{
  return Pos() + Avaible() == Size();
}

bool stream::CanWrite( void ) const
{
  return can_write;
}

bool stream::CanRead( void ) const
{
  return can_read;
}

bool stream::IsBlocked( void ) const
{
  return !CanWrite() && !CanRead();
}

bool stream::IsTwoWay( void ) const
{
  return CanWrite() && CanRead();
}

void stream::DeAttach( stream *const source )
{
  throw_assert(source);
  throw_assert(in == source);
  throw_assert(source->out == this);
  source->out = NULL;
  if (source->destroy_by_out)
    delete source;
  in = NULL;
  if (destroy_by_in)
    delete this;
}

stream *const stream::Attach( stream *const source, bool destroy_source_when_ends, bool destroy_when_source_ends )
{
  throw_assert(source);
  throw_assert(!in);
  throw_assert(!source->out);
  throw_assert(source->CanRead());
  throw_assert(CanWrite());

  in = source;
  source->out = this;
  source->destroy_by_out = destroy_when_source_ends;
  destroy_by_in = destroy_when_source_ends;
  return source;
}

ax::mem::fast_offset_mem stream::Steal( word &stealed, word how_much )
{
  if (in)
    return in->Steal(stealed, how_much);
  return Read(stealed, how_much);
}

void stream::SetDestroyByIn( bool cond )
{
  destroy_by_in = cond;
}

void stream::SetDestroyByOut( bool cond )
{
  destroy_by_out = cond;
}


