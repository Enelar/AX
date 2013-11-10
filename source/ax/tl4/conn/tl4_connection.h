/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_CONNECTION_H_
#define _AX_TL4_CONNECTION_H_

#include "../tl4.h"
#include "../../stream/stream_pipe.h"

namespace ax
{
  namespace tl4
  {
    class connection : protected tl4_hash
    {
      bool attached;
      connection( network *con );
    public:
      typedef ax::streams::stream default_container;
      connection( const connection &c );
      connection &operator=( const connection &c );
      bool operator<<( const connection &c );
      void Close();
      void DeAttach();
      ~connection();

      bool Send( default_container *mes );
      bool SendAndDestroy( default_container *mes );
      default_container *Recieve();

    private:
      void Attach();
      friend class network;
    };
  };
};

#endif