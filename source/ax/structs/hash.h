/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STRUCTS_HASH_H_
#define _AX_STRUCTS_HASH_H_

#include "..\def.h"

namespace ax
{
  namespace structs
  {
    template<class Tkey = word, class Tvalue = word>
    class hash
    {
    protected:
      mutable Tvalue value;
    public:
      Tkey key;
      hash( const hash &a ) : key(a.key), value(a.value)
      {
      }
      hash( const Tkey &k = 0, const Tvalue &v = 0 ) : key(k), value(v)
      {
      }
      const hash &operator=( const hash &h )
      {
        key = h.key;
        value = h.value;
        return *this;
      }
      const hash &operator<<( Tvalue h ) const
      {
        value = h;
        return *this;
      }
      const Tvalue V( ) const
      {
        return value;
      }
      const hash &operator=( const Tkey &k )
      {
        key = k;
        return *this;
      }
      operator Tkey( ) const
      {
        return key;
      }
      bool operator==( const hash &h ) const
      {
        return key == h.key;
      }
      bool operator!=( const hash &h ) const
      {
        return (*this) == h;
      }
      typedef Tkey key_type;
      typedef Tvalue val_type;
    };

    typedef hash<> dhash;
  };
};

#endif