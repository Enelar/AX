/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "../def.h"
#include "utils.h"

#include "memcpy.h"

//#define _CRT_MEMORY_DEFINED
void ax::MemCpy( void *const destination, const void *const source, const sst length )
{
  ax_memcpy(destination, source, length);
}


#include <string.h>

sst ax::StrLen( const char *const str )
{
  return strlen(str);
}

sst ax::StrLenSafeFast( char *const str, const sst buf_size )
{
  throw_assert(buf_size);
  sst index = buf_size - 1;
  char ch = str[index];
  if (!ch)
    return StrLen(str);
  str[index] = 0;
  sst len = StrLen(str);
  str[index] = ch;
  return len;
}

#define TOBIG(a) ((a) > 'Z' ? ((a) - ('a' - 'A')) : (a))

bool DummyCmp( char a, char b )
{
  return TOBIG(a) == TOBIG(b);
}

sst ax::StrMasqEq( const char *str, const char *mask )
{
  word len = 0;
  while (*mask && *str && DummyCmp(*str++, *mask++))
    ++len;
  if (*mask == 0)
    return len;
  return 0;
}

sst ax::StrFastCopy( char *&dest, const char * const source )
{
  throw_sassert(dest == nullptr, "Destination of StrFastCopy not empty");
  sst len = StrLen(source) + 1;

  struct dummy_smart_ptr
  {
    char *ptr;
    dummy_smart_ptr() : ptr(nullptr)
    {}
    ~dummy_smart_ptr()
    { 
      if (ptr != nullptr)
        delete []ptr;
    }
  } memory_guard;
  memory_guard.ptr = NEW char[len];
  MemCpy(memory_guard.ptr, source, len);
  dest = memory_guard.ptr;
  memory_guard.ptr = nullptr;
  return len - 1;
}
