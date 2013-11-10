/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "stream.h"

#ifndef _AX_STREAM_PIPE_H_
#define _AX_STREAM_PIPE_H_

#include <list>

namespace ax
{
  namespace streams
  {
    class pipe : public stream
    {
    protected:
      dword size, pos, buffered, pass;
      std::list<default_buffer> buffer;
    public:
      virtual dword Avaible( void ) const;
      virtual dword Pos( void ) const;
      virtual dword Size( void ) const;

      virtual default_buffer Read( dword &readed, const dword count = 0);
      virtual void SlowRead( ub *const &buffer, dword &readed, const dword count );
      virtual void Add( ub *&buf, const dword size );
      virtual void Fill( const ub *const ub, const dword size );
      virtual void End( );
    };
  };
};

#endif