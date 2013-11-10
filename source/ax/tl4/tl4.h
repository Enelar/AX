/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_H_
#define _AX_TL4_H_

#include "../structs/local_db.h"
#include "../stream/stream.h"
#include "../units/timestamp.h"
#include "sys/tl4_status.h"

namespace ax
{
  namespace tl4
  {
    class network;
    network CreateSubNetwork( const ax::units::timestamp &cur );
    const char *const getVersion();
    const char *const getFeatures();

    class tl4_hash
    {
    public:
      network *const net;
      ax::structs::dhash h;

      tl4_hash( network *const n ) : net(n)
      {}
    };
  };
};

namespace ax
{
  namespace tl4
  {
    struct info
    {
      const unsafe_dword ip;
      const unsafe_word port;
      info( unsafe_dword i, unsafe_word p) : ip(i), port(p)
      {}
    };
    class port;
    class connection;
    struct system_connection;
    typedef bool (*tl4_listener_inc_con)( port &p, connection &c );
    typedef bool (*tl4_listener_client_disc)( port &p, connection &c );
    typedef bool (*tl4_listener_disc)( connection &c );
    typedef bool (*tl4_listener_inc_mes)( connection &c, ax::streams::stream *const mes );
    typedef system_connection *(*tl4_inc_con_maker)(const ax::units::timestamp &current_time);
  };
};

//#include "mes/tl4_crypt.h"
//#include "mes/tl4_translator.h"
#include "port/tl4_port.h"
#include "net/tl4_network.h"
#include "conn/tl4_connection.h"

#endif