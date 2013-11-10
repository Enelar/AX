#include "../tl4.h"
#include "../sys/tl4_storage.h"

using namespace ax::tl4;

port network::OpenPort( const word port, 
   const tl4_inc_con_maker inc_maker, 
   ax::units::timestamp &ot, 
   tl4_listener_client_disc od, 
   tl4_listener_inc_con ic )
{
  system_port *sp = NEW system_port(inc_maker, ot, od, ic);
  tl4_hash h(this);
  h.h = store->port.ImportData(sp);
  return ax::tl4::port(h);
}