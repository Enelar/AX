/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_H_
#define _AX_STREAM_H_

#include "../def.h"
#include "../memory/mem.h"

namespace ax
{
  namespace streams
  {
    class stream
    {
    protected:
      stream *out, *in;
      bool can_write, can_read;
      bool destroy_by_out,
           destroy_by_in;
      virtual void Default( void );
    public:
      typedef ax::mem::fast_offset_mem default_buffer;
      stream( void );
      stream( stream *const source );
      virtual ~stream( void );
      virtual word Avaible( void ) const;
      virtual word Pos( void ) const;
      virtual word Size( void ) const;

      virtual bool CanWrite( void ) const;
      virtual bool CanRead( void ) const;
      virtual bool IsBlocked( void ) const;
      virtual bool IsTwoWay( void ) const;

      virtual bool IsBegin( void ) const;
      virtual bool IsEnd( void ) const;
      virtual bool Finished( void ) const;

      virtual default_buffer Read( word &readed, const word count = 0) = 0;
      virtual void SlowRead( ub *const &buffer, word &readed, const word count ) = 0;
      virtual void Add( ub *&buf, const word size );
      virtual void Fill( const ub *const ub, const word size );
      virtual void End( );

      virtual stream *const Attach( stream *const source,
        bool destroy_source_when_ends = true, 
        bool destroy_when_source_ends = false);
      virtual void DeAttach( stream *const connect );

      virtual default_buffer Steal( word &stealed, word how_much );

      virtual void SetDestroyByIn( bool cond );
      virtual void SetDestroyByOut( bool cond );
    };
  };
};

#endif