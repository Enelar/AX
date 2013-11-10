/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "..\def.h"
#include <time.h>
#include <stdio.h>

using namespace ax;

namespace
{
  void Replace( char *&base, unsigned int offset, char *add )
  {
    dword base_len = StrLen(base);
    dword add_len = StrLen(add);
    dword new_len = base_len - offset + add_len;
    char *ret = NEW char[new_len + 1];
    MemCpy(ret, add, add_len);
    MemCpy(ret + add_len, base + offset, base_len - offset);
    ret[new_len] = 0;
    delete base;
    base = ret;
  }
};

void ax_exception::InitStrings( const int i, const char *const f )
{
  char str[100];
  sprintf_s(str, 100, "Error code: %i", i);
  InitStrings(str, f);
}

void ax_exception::InitStrings( const char *const str, const char *const f )
{
  dword size;
  string = NEW char[size = StrLen(str) + 1];
  MemCpy(string, str, size);
  file = NEW char[size = StrLen(f) + 1];
  MemCpy(file, f, size);
  if (global_filename_replacer)
    global_filename_replacer(file, Replace);
}

ax_exception::ax_exception( ax_exception &a ) : line(a.line), time(a.time)
{
  InitStrings(a.string, a.file);
}

ax_exception::~ax_exception( void )
{
  if (string)
    delete string;
  if (file)
    delete file;
}

const char *const ax_exception::GetString( void ) const
{
  return string;
}
const char *const ax_exception::GetFile( void ) const
{
  return file;
}
const int ax_exception::GetLine( void ) const
{
  return line;
}
const int ax_exception::GetTime( void ) const
{
  return time;
}

bool ax_exception::CallExceptionHandler( void )
{
  return global_handler && global_handler(this);
}

//bool (*ax::ExceptionHandler)( const ax_exception *const exception ) = NULL;

exception_handler ax::ax_exception::global_handler = NULL;
cut_filename ax::ax_exception::global_filename_replacer = NULL;