#include "tl4_network.h"
#include "../sys/tl4_storage.h"
#include "../low/tl4_low.h"
#include "../conn/tl4_connection.h"

using namespace ax::tl4;
using namespace ax::structs;

connection network::OpenConnection( const word ip, const hword port,
  crypt *en, crypt *de, outcome_translator *ot, income_translator *it,
   tl4_listener_disc on_disc, tl4_listener_inc_mes on_mes )
{
  dhash h = store->con.ImportData(NEW system_connection(en, de, ot, it, on_disc, on_mes));
  system_connection *c = store->con[h];

  c->ip = ip;
  c->port = port;
  c->status = TL4_CON_PRECONNECTING;

  connection ret = connection(this);
  ret.h = h;
  return ret;
}

connection network::OpenConnection( const char *const addr, const word port,
  crypt *en, crypt *de, outcome_translator *ot, income_translator *it,
   tl4_listener_disc on_disc, tl4_listener_inc_mes on_mes )
{
  dhash h = store->con.ImportData(NEW system_connection(en, de, ot, it, on_disc, on_mes));
  system_connection *c = store->con[h];

  StrClone(c->host, addr);
  c->port = port;
  c->status = TL4_CON_PRE_IP_RESOLV;

  connection ret = connection(this);
  ret.h = h;
  return ret;
}