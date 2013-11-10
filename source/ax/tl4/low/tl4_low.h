/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_LOW_H_
#define _AX_TL4_LOW_H_

#include "../sys/tl4_def.h"

namespace ax
{
  namespace tl4
  {
   enum LOW_STATUSES
    {
      SUCCESS = 0,
      NO_MESSAGES,
      TRYING_CONNECT,
      PLEASE_WAIT,
      CANT_CREATE_SOCKET,
      CANT_RESOLVE_IP,
      LOW_CONNECTION_REFUSED,
      CANT_BIND,
      CANT_LISTEN,
      DISCONNECT
    };

    struct low
    {
      friend class network;
      friend class connection_response;

      static LOW_STATUSES Connect( unsafe_dword &socket,
        const unsafe_dword addr, const unsafe_word port );

      static LOW_STATUSES Send( const unsafe_dword  socket, 
        const unsafe_byte *const buff, const word size );

      static LOW_STATUSES Recieve( const unsafe_dword socket, 
        unsafe_byte *const buff, word &readed, word read = _TL4_DATA_SEGMENT_SIZE );

      static LOW_STATUSES Close( unsafe_dword &socket );

      static LOW_STATUSES Open( unsafe_dword &socket, 
        const unsafe_word port, const unsafe_word max_connections );

      static LOW_STATUSES GetIp( const char * const addr, unsafe_dword &ip );

      static LOW_STATUSES SetBacklog( const unsafe_dword socket, 
        const unsafe_word max_connections );

      static udw Accept( const unsafe_dword socket, 
        unsafe_dword &ip, unsafe_word &port );
    };
  };
};

#endif