/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TYPES_H_
#define _AX_TYPES_H_

#ifndef _AX_FUNDAMENTAL_TYPES_BASED_ON_CPP_STANDART
/*/ Cause typedef impelemtation bug:
typedef __int8 test;
typedef unsigned test a; // test redefinition
===
typedef __int8 test;
typedef unsigned __int8 a; // ok
//*/

#define _ax_basic_byte_         __int8
#define _ax_basic_half_word_    __int16
#define _ax_basic_word_         __int32
#define _ax_basic_double_word_  __int64
#define _ax_basic_biggest_word_ __int64
#else
#define _ax_basic_byte_         char
#define _ax_basic_half_word_    short
#define _ax_basic_word_         int
#define _ax_basic_double_word_  long long
#define _ax_basic_biggest_word_ long long
#endif

typedef unsigned  _ax_basic_byte_         unsafe_byte, ub;
typedef unsigned  _ax_basic_half_word_    unsafe_hword, uhw;
typedef unsigned  _ax_basic_word_         unsafe_word, uwd, uw, uint;
typedef unsigned  _ax_basic_double_word_  unsafe_dword, udw;
typedef unsigned  _ax_basic_biggest_word_ unsafe_bword, ubw;
typedef           _ax_basic_word_         unsafe_int, ui;
typedef           _ax_basic_biggest_word_ unsafe_bigint, ubi;
typedef           size_t                  usst;

#define GETMAXCOUNT(BITS) ((unsafe_bword)1 << (BITS))
#define GETMAXVALUE(BITS) (GETMAXCOUNT(BITS - 1) - 1 + GETMAXCOUNT(BITS - 1))

#define BITSINBYTE 8
#define MAXVALUEBYTYPE(type) GETMAXVALUE(BITSINBYTE * sizeof(type))

#define BYTE_MAX  MAXVALUEBYTYPE(ub)
#define HWORD_MAX MAXVALUEBYTYPE(uhw)
#define WORD_MAX  MAXVALUEBYTYPE(uw)
#define DWORD_MAX MAXVALUEBYTYPE(udw)
#define BWORD_MAX MAXVALUEBYTYPE(ubw)

// Warning, maybe bug!
#define CIFRA_MAX     (MAXVALUEBYTYPE(ui) >> 1)
#define BIGINT_MAX  (MAXVALUEBYTYPE(ubi) >> 1)

//#if _DEBUG_
#ifdef _DEPRECATED_DUE_REFACTOR_

namespace ax
{
  template<typename t>
  int Sign( const t a );
};

#pragma warning(disable: 4146)
template<typename type, int is_unsigned = true>
class safe_constructor
{
  template<typename type, int is_unsigned> friend class safe_constructor;
  type val;
  bool defined;
public:
  typedef safe_constructor sc;
  safe_constructor( const type init ) : defined(true)
  {
    *this = init;
  }
  safe_constructor( void ) : defined(false)
  {
  }
  template<typename t>
  safe_constructor( const safe_constructor<t> &a ) : defined(true)
  {
    *this = static_cast<type>(a.val);
  }
  operator type( void ) const
  {
    return val;
  }
  template <typename t>
  const type &operator=( const t &a )
  {
    if (!defined)
      defined = true;
    type v = static_cast<type>(a);
    throw_sassert((v - a) == 0, "Unsafe operation with safe variable");
    return val = v;
  }
  const sc &operator+=( const sc &a )
  {
    throw_assert(defined);
    if (!is_unsigned && a < 0)
      return *this -= -a;
    throw_assert(val + a >= val);
    val += a;
    return *this;
  }
  const sc &operator-=( const sc &a )
  {
    throw_assert(defined);
    if (!is_unsigned && a < 0)
      return *this += -a;
    throw_assert(val - a <= val);
    val -= a;
    return *this;
  }
  const sc operator*=( const sc &a )
  {
    if (is_unsigned)
    {
      unsigned long long b = (unsigned long long)a*val;
      if (b > MAXVALUEBYTYPE(type))
        throw_exception("Multiply overflow");
      val = (~type(0)) & b;
    } else
    {
      long long b = (long long)a*val;
      if (b > MAXVALUEBYTYPE(type) / 2)
        throw_exception("Multiply overflow");
      val = (~type(0)) & b;
      if (ax::Sign(val) != ax::Sign(b))
        val *= -1;
    }
    if (sizeof(type) >= 8)
      todo(multiply);
    return val;
    /*
    Multiplying two 64-bit integers

But what if we want to multiply two 64-bit numbers and there is no 128-bit type? Then we need to do the multiplication by hand. To do that, we split both number in two 32-bit parts. Let's write "<< 32" as "* shift" to make this easier to read. Basically if we write the first number as a1 shift + a0 and the second number as b1 shift + b0, then the product is

  (a1 shift + a0) * (b1 shift + b0) ==
  a1 b1 shift shift + a1 b0 shift + a0 b1 shift + a0 b0
The first term is shifted by 64 bits, so if both a1 and b1 are nonzero, we have an overflow right there and can abort.

For the second and third part we do the 32x32->64 multiplication we just used to check for overflow for 32-bit numbers. This is shifted by 32 bits, so we have an overflow if the upper half of it is nonzero. Since we already know that either a1 or b1 is zero, we can simply calculate

  a=(uint64_t)(a1)*b0+(uint64_t)(a0)*b1;
At least one half of this term will be zero, so we can't have an overflow in the addition. Then, if a > 0xffffffff, we have an overflow in the multiplication and can abort.

If we got this far, the result is

  (a << 32) + (uint64_t)(a0)*b0;
We still need to check for overflow in this addition (thanks to Tomi Jylhä-Ollila for pointing this out). Then we can return the result.
*/
  }
  const sc &operator/=( const sc &a )
  {
    throw_assert(defined);
    todo(divide);
  }
  const sc &operator++( )
  {
    return this->operator+=(1);
  }
  sc operator++( int )
  {
    ++*this;
    return sc(val - 1);
  }
  const sc &operator--( )
  {
    return this->operator-=(1);
  }
  sc operator--( int )
  {
    --*this;
    return sc(val + 1);
  }
};
#pragma warning(default: 4146)

#ifdef _UNDER_BILL_GATES_
#ifndef _BYTE
#define _BYTE
#endif
typedef ub byte;
#endif

#ifndef _BWORD
typedef safe_constructor<unsafe_bword> bword;
#endif
#ifndef _DWORD
typedef safe_constructor<unsafe_dword> dword;
#endif
#ifndef _WORD
typedef safe_constructor<unsafe_word>   word;
#endif
#ifndef _LETTER
typedef safe_constructor<unsafe_byte> LETTER;
#endif
#ifndef _CIFRA
typedef safe_constructor<unsafe_int>          cifra;
#endif
#ifndef _BIGINT
typedef safe_constructor<unsafe_bigint> bigint;
#endif
#ifndef _FLT
typedef float                            flt;
#endif
#ifndef _DBL
typedef double                           dbl;
#endif
#ifndef _LDBL
typedef long double                     ldbl;
#endif
#ifndef _SST
typedef safe_constructor<usst>           sst;
#endif

/*
#define OPERATOR(op)                                                                                       \
  template <typename type>                                                                                       \
  const safe_constructor<type> operator##op( const safe_constructor<type> &a, const safe_constructor<type> &b )    \
  {                                                                                                              \
    safe_constructor<type> t = a;                                                                                \
    t op##= b;                                                                                                      \
    return t;                                                                                                    \
  }                                                                                                              \
  template <typename type>                                                                                       \
  const safe_constructor<type> operator##op( const type &a, const safe_constructor<type> &b )                      \
  {                                                                                                              \
    safe_constructor<type> t = a;                                                                                \
    t op##= b;                                                                                                      \
    return t;                                                                                                    \
  }                                                                                                              \
  template <typename type>                                                                                       \
  const safe_constructor<type> operator##op( const safe_constructor<type> &a, const type &b )                      \
  {                                                                                                              \
    safe_constructor<type> t = a;                                                                                \
    t op##= b;                                                                                                   \
    return t;                                                                                                    \
  }                                                                                                              
OPERATOR(+)
OPERATOR(-)
OPERATOR(*)
OPERATOR(/)
OPERATOR(|)
OPERATOR(&)
*/

template <typename type>
const safe_constructor<type> operator|( const safe_constructor<type> a, const safe_constructor<type> b )
{
  safe_constructor<type> t = a;
  t |= b;
  return t;
}
template <typename type>
const safe_constructor<type> operator&( const safe_constructor<type> a, const safe_constructor<type> b )
{
  safe_constructor<type> t = a;
  t &= b;
  return t;
}

template <typename type>
const safe_constructor<type> operator+( const safe_constructor<type> &a, const safe_constructor<type> &b )
{
  safe_constructor<type> t = a;
  t += b;
  return t;
}
template <typename type>
const safe_constructor<type> operator-( const safe_constructor<type> &a, const safe_constructor<type> &b )
{
  safe_constructor<type> t = a;
  t -= b;
  return t;
}
template <typename type>
const safe_constructor<type> operator*( const safe_constructor<type> &a, const safe_constructor<type> &b )
{
  safe_constructor<type> t = a;
  t *= b;
  return t;
}
template <typename type>
const safe_constructor<type> operator/( const safe_constructor<type> &a, const safe_constructor<type> &b )
{
  safe_constructor<type> t = a;
  t /= b;
  return t;
}

#else
typedef unsafe_bword   bword;
typedef unsafe_dword   dword;
typedef unsafe_word     word;
typedef unsafe_hword   hword;
typedef unsafe_byte     byte;
typedef unsafe_int     cifra;
typedef unsafe_bigint bigint;
typedef float            flt;
typedef double           dbl;
typedef long double     ldbl;
typedef usst             sst;
#endif

namespace ax
{
  void CheckTypes( void );

  class object
  {
  public:
    virtual ~object()
    {}
  };

  class copyable : public object
  {
  public:
    virtual copyable *Copy( void ) const = 0;
  };

  class shared : public object
  {
  protected:
    dword users;
  public:
    shared();
    virtual void AddShare( );
    virtual void RemoveShare( );
    ~shared();
  };

  class shared_self_controlled : public shared
  {
  public:
    virtual void RemoveShare( );
  };
};

#endif