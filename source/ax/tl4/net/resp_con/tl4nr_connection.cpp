#include "tl4nr_connection.h"
#include "../../sys/tl4_storage.h"
#include "../../conn/tl4c_system.h"

using namespace ax::tl4;

connection_response::connection_response( storage *const s ) : store(s)
{
  throw_assert(s);
  s->AddShare();
}

void connection_response::ProcessAllConnections( const ax::units::timestamp &t )
{
  dword i = 0, s = store->con.GetSize();
  while (i < s)
  {
    system_connection *cp = store->con(i);
    throw_assert(cp);
    system_connection &c = *cp;
    STAT_CON status = c.status;
    if (status <= TL4_CON_IP_RESOLV)
      ResolveHandler(c);
    else if (status <= TL4_CON_RECONNECTING)
      ConnectHandler(c);
    else if (status <= TL4_CON_TRANSFER)
      TransferHandler(c);
    else
      switch (status)
      {
      case TL4_CON_CLOSING:
        CloseHandler(c);
        break;
      case TL4_CON_CLOSED:
        CleanHandler(c);
        break;
      case TL4_CON_CANTRESOLVE:
      case TL4_CON_TRANSFERERROR:
      case TL4_CON_TIMEOUT:
      case TL4_CON_REFUSED:
        CleanHandler(c);
        break;
      case TL4_CON_FREE:
      case TL4_CON_DISCONNECTED:
        break;
      }
    ++i;
  }
  todo("Process connections");
}

connection_response::~connection_response()
{
  store->RemoveShare();
}