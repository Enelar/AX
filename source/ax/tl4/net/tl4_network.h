/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_NETWORK_H_
#define _AX_TL4_NETWORK_H_

#include "../tl4.h"

namespace ax
{
  namespace tl4
  {
    struct storage;
    class crypt;
    class outcome_translator;
    class income_translator;

    class network
    {
      friend network CreateSubNetwork( const ax::units::timestamp &cur );
    private:
      storage *const store;
      network( const ax::units::timestamp &cur );
    public:
      //! BUG: stack corrupt
      //ax::units::timestamp t_current;

      network( const network &n );
      network &operator=( const network &n );
      ~network();

      void Response( const ax::units::timestamp &t );
      dword GetConnectionsCount() const;
      port OpenPort( const word port, const tl4_inc_con_maker inc_maker, ax::units::timestamp &ot, tl4_listener_client_disc od = NULL, tl4_listener_inc_con ic = NULL );
      connection OpenConnection( const dword ip, const word port,
        crypt *en = NULL, crypt *de = NULL,
        outcome_translator *ot = NULL, income_translator *it = NULL,
        tl4_listener_disc on_disc = NULL, tl4_listener_inc_mes on_mes = NULL );
      connection OpenConnection( const char *const addr, const word port,
        crypt *en= NULL, crypt *de = NULL,
        outcome_translator *ot = NULL, income_translator *it = NULL,
        tl4_listener_disc on_disc = NULL, tl4_listener_inc_mes on_mes = NULL );

      friend class connection;
    };
  };
};

#endif