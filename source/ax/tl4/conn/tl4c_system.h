/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */
#ifndef _AX_TL4_C_SYSTEM_H_
#define _AX_TL4_C_SYSTEM_H_

#include "../tl4.h"
#include "../sys/tl4_def.h"
#include "../mes/tl4_crypt.h"
#include "../../stream/stream_pump.h"

namespace ax
{
  namespace tl4
  {
    struct package
    {
      byte net_id;
      ax::streams::stream *mes;
      bool handled;
      package( void );
      ~package( void );
    };
    class outcome_translator;
    class income_translator;
    struct system_connection : protected shared_self_controlled
    {
      unsafe_dword socket;
      STAT_CON status;

      ax::units::timestamp t_open, t_la;
      ax::streams::pump unsended, unparsed;

      tl4_listener_disc on_disc;
      tl4_listener_inc_mes on_mes;

      typedef ax::structs::local_db<package> message_buffer;
      message_buffer output;
      message_buffer input, finished_input;

      crypt *encrypt, *decrypt;
      outcome_translator *out_translator;
      income_translator *in_translator;

      char *host;
      unsafe_dword ip;
      unsafe_word port;

      system_connection( crypt *en, crypt *de, outcome_translator *ot, income_translator *it,
         tl4_listener_disc on_disc, tl4_listener_inc_mes on_mes );
      ~system_connection();

      friend class connection;
    };
  };
};

#include "../mes/tl4_translator.h"


#endif