#include "../sys/tl4_def.h"
#include "tl4_network.h"
#include "resp_con/tl4nr_connection.h"

using namespace ax::tl4;

namespace
{
  void ProcessConnections( const ax::units::timestamp &t )
  {

  }
};

void network::Response( const ax::units::timestamp &t )
{
  connection_response c(store);
  c.ProcessAllConnections(t);
}