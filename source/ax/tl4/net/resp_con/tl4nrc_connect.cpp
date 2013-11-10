#include "tl4nr_connection.h"
#include "../../low/tl4_low.h"
#include "../../conn/tl4c_system.h"

using namespace ax::tl4;

void connection_response::ConnectHandler( system_connection &c )
{
  if (c.status != TL4_CON_RECONNECTING)
    c.status = TL4_CON_CONNECTING;
  LOW_STATUSES s = low::Connect(c.socket, c.ip, c.port);
  if (s == CANT_CREATE_SOCKET)
    c.status = TL4_CON_DENIED;
  if (s == TRYING_CONNECT)
    return;
  if (s == LOW_CONNECTION_REFUSED)
    c.status = TL4_CON_REFUSED;
  if (s == SUCCESS)
    c.status = TL4_CON_CONNECTED;
}