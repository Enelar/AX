#include "tl4_network.h"
#include "../sys/tl4_storage.h"

using namespace ax::tl4;

network ax::tl4::CreateSubNetwork( const ax::units::timestamp &cur )
{
  return network(cur);
}

network::network( const ax::units::timestamp &cur ) : store(NEW storage())//, t_current(cur)
{
  store->AddShare();
}

network::network( const network &n ) : store(n.store)//, t_current(n.t_current)
{
  store->AddShare();
}

network &network::operator=( const network &n )
{
  throw_message("Unsupported");
}

network::~network()
{
  store->RemoveShare();
}