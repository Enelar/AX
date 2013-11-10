/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _TL4_NETWORK_RESPONSER_CONNECTION_H_
#define _TL4_NETWORK_RESPONSER_CONNECTION_H_

#include "../../../units/timestamp.h"

namespace ax
{
  namespace tl4
  {
    struct storage;
    struct system_connection;

    class connection_response
    {
      storage *const store;
      void ResolveHandler( system_connection & );
      void ConnectHandler( system_connection & );
      void TransferHandler( system_connection & );
      void CloseHandler( system_connection & );
      void CleanHandler( system_connection & );
    public:
      connection_response( storage *const );
      void ProcessAllConnections( const ax::units::timestamp &t );
      ~connection_response();
    };
  };
};

#endif