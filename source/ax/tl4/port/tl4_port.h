/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_PORT_H_
#define _AX_TL4_PORT_H_

#include "../tl4.h"

namespace ax
{
  namespace tl4
  {
    class port : protected tl4_hash
    {
      friend class network;
      port( const tl4_hash &h );
      tl4_hash next_c;
    public:
      bool Close();
      bool DeAttach();
      connection GetNextConnection();

      port( const port &p );
      ~port();
    };
  };
};

#endif
