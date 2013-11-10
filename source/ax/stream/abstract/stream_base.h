/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_BASE_H_
#define _AX_STREAM_BASE_H_

#include "../../def.h"

namespace ax
{
  namespace streams
  {
    class stream_base : public object
    {
    private:
      bool Fail, // any error occure
           End, // is end of stream data
           Inited;
      typedef void (*callback) ();
    protected:
      void ChangeFailFlag( bool status );
      void ChangeEndFlag( bool status );
      void ChangeInitedFlag( bool status );
      stream_base( bool inited_by_default );

      virtual void OnFail();
      virtual void OnEnd();
      virtual void OnInit();
      virtual void OnDeinit();

    public:
      bool IsFail() const;
      bool IsEnd() const;
      bool IsInit() const;
    };
  };
};

#endif