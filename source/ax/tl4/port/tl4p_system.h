/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_P_SYSTEM_H_
#define _AX_TL4_P_SYSTEM_H_

#include "../sys/tl4_def.h"
#include "../conn/tl4c_system.h"

namespace ax
{
  namespace tl4
  {
    struct system_port : protected shared_self_controlled
    {
      dword socket;
      STAT_PORT status;

      word number; // port number
      const tl4_inc_con_maker maker;
      ax::units::timestamp open_time;

      word max, online;
      ax::structs::local_db<tl4_hash> connections;
      const tl4_listener_client_disc on_disc;
      const tl4_listener_inc_con on_con;

      system_port( const tl4_inc_con_maker inc_maker, ax::units::timestamp &ot, tl4_listener_client_disc od = NULL, tl4_listener_inc_con ic = NULL );
      ~system_port();
    };
  };
};

#endif