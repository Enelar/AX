/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_STORAGE_H_
#define _AX_TL4_STORAGE_H_

#include "../tl4.h"
#include "../conn/tl4c_system.h"
#include "../port/tl4p_system.h"
#include "../../structs/local_db.h"

namespace ax
{
  namespace tl4
  {
    struct system_connection;
    struct system_port;
    struct storage : public shared_self_controlled
    {
      friend class network;
      ax::structs::local_db<system_connection> con;
      ax::structs::local_db<system_port> port;
      dword online; // what that means?
      bool isTL4;

      storage( void ) : online(0), isTL4(true)
      {
      }
    };
  };
};

#endif