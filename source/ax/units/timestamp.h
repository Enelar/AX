/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_UNITS_TIMESTAMP_H_
#define _AX_UNITS_TIMESTAMP_H_

#include "../def.h"

namespace ax
{
  namespace units
  {
    class real_timestamp
    {
      void GetCurrent();
    protected:
      dword sec;
      dword ms;
      void Init( const dword s, const dword m );
    public:
      real_timestamp();
      real_timestamp( const real_timestamp &a );
      operator dbl() const;
      virtual real_timestamp &operator=( const real_timestamp &t );
    };
    class timestamp : public real_timestamp
    {
      bool is_real;
    public:
      bool IsReal() const;
      timestamp( );
      timestamp( const timestamp &t );
      timestamp( const real_timestamp &t );
      virtual timestamp &operator=( const timestamp &t );
      virtual real_timestamp &operator=( const real_timestamp &t );
    };
  };
};

#endif