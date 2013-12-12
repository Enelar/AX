/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "../sys/tl4_def.h"
#include "../tl4.h"
#include "tl4c_system.h"

using namespace ax::tl4;

package::package( void ) : net_id(0), mes(NULL), handled(0)
{
}
package::~package( void )
{
  if (mes)
  {
    delete mes;
    mes = NULL;
  }
  if (net_id)
  {
    net_id = 0;
    throw_message("TL4 protocol error: Deleting active package.");
  }
}

system_connection::system_connection( 
    crypt *en, crypt *de, 
   outcome_translator *ot, income_translator *it,
  tl4_listener_disc od, tl4_listener_inc_mes om )

:
socket(_TL4_NOT_SOCKET_),
encrypt(en), decrypt(de),
out_translator(ot), in_translator(it), 
on_disc(od), on_mes(om),
status(TL4_CON_FREE),
ip(_TL4_NOT_IP_), port(_TL4_NOT_PORT_), host(NULL)
{
  throw_assert(en);
  throw_assert(de);
  throw_assert(ot);
  throw_assert(it);
}

system_connection::~system_connection()
{
  delete encrypt;
  delete decrypt;
  delete out_translator;
  delete in_translator;
  delete host;
}