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
      word size, pos, buffered, pass;
      std::list<default_buffer> buffer;
    public:
      virtual word Avaible( void ) const;
      virtual word Pos( void ) const;
      virtual word Size( void ) const;

      virtual default_buffer Read( word &readed, const word count = 0);
      virtual void SlowRead( ub *const &buffer, word &readed, const word count );
      virtual void Add( ub *&buf, const word size );
      virtual void Fill( const ub *const ub, const word size );
      virtual void End( );
    };
  };
};

#endif