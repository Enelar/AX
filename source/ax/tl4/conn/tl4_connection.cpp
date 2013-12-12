#include "../sys/tl4_def.h"
#include "tl4_connection.h"
#include "tl4c_system.h"
#include "../sys/tl4_storage.h"

using namespace ax::tl4;

connection::connection( const connection &c ) : tl4_hash(c.net), attached(false)
{
  (*this) = c;
}
connection &connection::operator=( const connection &c )
{
  throw_assert(net == c.net);
  if (h != c.h)
  {
    if (attached)
      DeAttach();
    h = c.h;
    Attach();
  }
  return *this;
}

connection::connection( network *con ) : tl4_hash(con), attached(false)
{
  Attach();
}

void connection::Attach()
{
  net->store->con[h]->AddShare();
  attached = true;
}

void connection::DeAttach()
{
  attached = false;
  net->store->con[h]->RemoveShare();
}