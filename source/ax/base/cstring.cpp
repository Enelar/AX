#ifndef _AX_UTILS_H_
#include "../def.h"
#else

template<typename char_t>
sst ax::StrLen( const char_t *const str )
{
  sst i = MAXVALUEBYTYPE(sst);
#if _DEBUG_
  throw_assert(i + 1 == 0);
#endif
  while (str[++i] != 0)
    ;
  return i;
}

template<typename char_t>
sst ax::StrLenSafeFast(char_t *const str, const sst buf_size)
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

template<typename char_t>
sst ax::StrMasqEq(const char_t *str, const char_t *mask)
{
  auto DummyCmp = []( char_t a, char_t b )
  {
    auto ToBig = []( char_t a ) -> char_t
    {
      if (a > 'Z')
        return a - ('a' - 'A');
      return a;
    };
    return ToBig(a) == ToBig(b);
  };

  word len = 0;
  while (*mask && *str && DummyCmp(*str++, *mask++))
    ++len;
  if (*mask == 0)
    return len;
  return 0;
}

template<typename char_t>
sst ax::StrClone(char_t *&dest, const char_t * const source)
{
  throw_sassert(dest == nullptr, "Destination of StrClone not empty");
  sst len = StrLen(source) + 1;

  try
  {
    dest = NEW char_t[len];
    MemCpy(dest, source, len * sizeof(char_t));
    return len - 1;
  } catch (...)
  {
    delete[]dest;
    throw;
  }
}

template<typename char_t>
char_t *ax::StrClone(const char_t * const source)
{
  char_t *ret = nullptr;
  StrClone(ret, source);
  return ret;
}

template<typename char_t>
sst ax::StrCopy(char_t *dest, const char_t *const source, const sst max_allowed_length)
{
  sst len = StrLen(source);
  throw_assert(len <= max_allowed_length);
  MemCpy(dest, source, (len + 1) * sizeof(char_t));
  return len;
}


#endif