#include "tl4nr_connection.h"
#include "../../low/tl4_low.h"
#include "../../conn/tl4c_system.h"

using namespace ax::tl4;

void connection_response::ResolveHandler( system_connection &c )
{
  c.status = TL4_CON_IP_RESOLV;
  LOW_STATUSES s;
  s = low::GetIp(c.host, c.ip);
  if (s == SUCCESS)
    c.status = TL4_CON_PRECONNECTING;
  if (s == CANT_RESOLVE_IP)
    c.status = TL4_CON_CANTRESOLVE;
}