#ifdef _AX_UTILS_H_

template<typename char_t>
sst ax::StrLen( const char_t *const str )
{
  return strlen(str);
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
    auto ToBig = []( char_t a )
    {
      if (a > 'Z')
        return a - ('a' - 'A');
      return a;
    }
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
sst ax::StrFastCopy(char_t *&dest, const char_t * const source)
{
  throw_sassert(dest == nullptr, "Destination of StrFastCopy not empty");
  sst len = StrLen(source) + 1;

  try
  {
    dest = NEW char_t[len];
    MemCpy(dest, source, len);
    return len - 1;
  } catch (...)
  {
    delete[]dest;
    throw;
  }
}

#endif