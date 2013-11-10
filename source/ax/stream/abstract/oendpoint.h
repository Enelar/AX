/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_OUT_ENDPOINT_H_
#define _AX_STREAM_OUT_ENDPOINT_H_

#include "stream_base.h"

namespace ax
{
  namespace streams
  {
    class oendpoint : public stream_base
    {
    private:
      bool CanRead;
    protected:
      oendpoint( bool can_read_default, bool inited_by_default );
      void ChangeReadFlag( bool status );

      virtual void OnReadEnabled();
      virtual void OnReadDisabled();
    public:
      bool IsCanRead() const;
    };
  };
};

#endif