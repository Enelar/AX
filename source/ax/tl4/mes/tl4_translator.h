/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_TRANSLATOR_H_
#define _AX_TL4_TRANSLATOR_H_

#include "../conn/tl4c_system.h"
#include "../../stream/stream_pump.h"

namespace ax
{
  namespace tl4
  {
    typedef system_connection::message_buffer mb;
    class outcome_translator : public object
    {
    public:
      // количество пропарсеных байт
      virtual dword Parse( ax::streams::pump *const to_send, mb output );
    };
    class income_translator : public object
    {
    public:
      // хоть одно сообщение завершилось?
      virtual bool Parse( ax::streams::pump *const recieved, mb input, mb finished_input );
    };
  };
};

#endif