/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_UNITS_TOGGLE_H_
#define _AX_UNITS_TOGGLE_H_

#include "../def.h"

namespace ax
{
  namespace units
  {
    class toggle
    {
      bool state;
    public:
      toggle( bool init = true );
      bool Next();
      bool State() const;

      bool TurnFalse();
      bool TurnTrue();

      bool IsChanged( const toggle & ) const;
      bool Update( const toggle & );

      operator bool &();
      operator bool() const;
    };
  };
};

#endif