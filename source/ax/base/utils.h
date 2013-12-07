/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_UTILS_H_
#define _AX_UTILS_H_

namespace ax
{
#define SER(a, t) (static_cast<t *>((void *)a))
#define DESER(a, t) (*(t *)a)
#define CAST(a, t) (*SER(&a, t))

#define ADDLA(obj, action) (obj) ? (obj)->action, true : false
#define ADDLB(obj, action) (obj) ? action, true : false
#define ADDLC(obj, action) (obj) ? (obj)->action : false

#define OUT

DEPRECATED
#define KIBI GETMAXCOUNT(10)
#define MIBI GETMAXCOUNT(20)
#define GIBI GETMAXCOUNT(30)
#define TIBI GETMAXCOUNT(40)
#define PIBI GETMAXCOUNT(50)

//*/ Wait for user-literal C++11 support
#define KB REQUIRE_CPP11 *KIBI
#define MB REQUIRE_CPP11 *MIBI
#define GB REQUIRE_CPP11 *GIBI
#define TB REQUIRE_CPP11 *TIBI
#define PB REQUIRE_CPP11 *PIBI

/*/ Wait for http://msdn.microsoft.com/en-us/library/hh567368
template<int amount, typename ret_type = word>
ret_type Multiplier(word number)
{
  return number << amount;
}

constexpr word operator"" GB(word a)
{
  return Multiplier<20>(a);
}
//*/

#define Min3(a, b, c) Min(Min(a, b), c)
#define Max3(a, b, c) Max(Max(a, b), c)

#define GLUE(a, b) a##b

  template<typename t1, typename t2>
  t1 Min( t1 &a, t2 &b )
  {
    return a < b ? a : b;
  }

  template<typename t1, typename t2>
  t1 Min( t1 a, t2 b )
  {
    return a < b ? a : b;
  }

  template<typename t1, typename t2>
  t1 Max( t1 &a, t2 &b )
  {
    return a < b ? b : a;
  }

  template<typename t1, typename t2>
  t1 Max( const t1 a, const t2 b )
  {
    return a < b ? b : a;
  }

  template<typename T>
  T Middle( const T a, const T b, const T c )
  {
    if (a < b)
      if (b < c)
        return b;
      else
        return Max(a, c);
    if (a > c)
      return a;
    return Max(b, c);
  }

  template<typename t>
  t Abs( const t a )
  {
    if (a >= 0)
      return a;
    return -a;
  }

  template<typename t>
  int Sign( const t a )
  {
    return a >= 0 ? 1 : -1;
  }

  template<typename t>
  bool IsPositive( const t a )
  {
    return a >= 0;
  }

  template<typename t>
  void Swap( t &a, t &b )
  {
    t c = a;
    a = b;
    b = c;
  }

  template<typename type>
  type GrowId( type &a )
  {
    if (a == GetMax(a))
      a = 0;
    return ++a;
  }

  template<typename type>
  void InRange( const type a, const type min, const type max )
  {
    throw_assert(a >= min);
    throw_assert(a <= max);
  }

  template<typename Tsuff, typename Tdegr = dword>
  struct Pow
  { 
    Tsuff res;
    Pow( const Tsuff a, const Tdegr level )
    {
      throw_assert(a || level);
      if (!a)
      {
        res = 0;
        return;
      }
      if (!level)
      {
        res = 1;
        return;
      }
      Tdegr cached_level = (Tdegr)(level);
      res = 1;

      if (level > 0)
        do
          res *= a;
        while (--cached_level);
      else
        do
          res /= a;
        while(++cached_level);
    }
    operator Tsuff( void )
    {
      return res;
    }
  };

  template<typename T>
  T Square( typename T )
  {
    return Pow<T>(T, 2);
  }


  template<typename char_t CPP11_ONLY(= char)>
  sst StrLen(const char_t *const str);

  template<typename char_t CPP11_ONLY(= char)>
  sst StrLenSafeFast(char_t *const str, const sst buf_size);

  template<typename char_t CPP11_ONLY(= char)>
  sst StrMasqEq(const char_t *str, const char_t *mask);

  template<typename char_t CPP11_ONLY(= char)>
  sst StrClone(char_t *&dest, const char_t *const source);

  template<typename char_t CPP11_ONLY(= char)>
  char_t *StrClone(const char_t *const source);

  template<typename char_t CPP11_ONLY(= char)>
  sst StrCopy(char_t *dest, const char_t *const source, const sst max_allowed_length );

  void MemCpy( void *const destination, const void *const source, const sst length );
  void MemMove( void *const destination, const void *const source, const sst length );
  inline unsafe_byte GetByte( const dword a, const int byte_number )
  {
    return (a >> (byte_number << 8)) & 255;
  }
}

#include "cstring.cpp"

#endif
