#include "tl4p_system.h"

using namespace ax::tl4;

system_port::system_port( const tl4_inc_con_maker inc_maker, 
                      ax::units::timestamp &ot, 
                      tl4_listener_client_disc od, 
                      tl4_listener_inc_con ic ) : 
maker(inc_maker), open_time(ot), on_disc(od), on_con(ic), status(TL4_PORT_FREE), socket(_TL4_NOT_SOCKET_)
{
}

system_port::~system_port()
{
}
