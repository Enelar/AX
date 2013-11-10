/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAM_IN_ENDPOINT_H_
#define _AX_STREAM_IN_ENDPOINT_H_

#include "stream_base.h"

namespace ax
{
  namespace streams
  {
    class iendpoint : public stream_base
    {
    private:
      bool CanWrite;
    protected:
      iendpoint( bool can_write_default, bool inited_by_default );
      void ChangeWriteFlag( bool status );

      virtual void OnWriteEnabled();
      virtual void OnWriteDisabled();
    public:
      bool IsCanWrite() const;
    };
  };
};

#endif