/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * Classes in this example could be viewed without Develop Project agreement
 * Classes in this example could be used without Develop Project agreement only for non-commerical
 */

#ifndef _AX_TL4_TRANSLATOR_SERIAL_H_
#define _AX_TL4_TRANSLATOR_SERIAL_H_

#include "tl4_translator.h"

namespace ax
{
  namespace tl4
  {
    class outcome_serial : public outcome_translator
    {
    public:
      virtual dword Parse( ax::streams::pump *const to_send, mb output )
      {
        if (!output.GetSize())
          return 0;
        dword parsed = 0;
        do
        {
          ax::streams::stream *cur = output(0)->data->mes;
          if (cur->IsEnd())
          {
            to_send->DeAttach(cur);
            output.DeleteEntry(0);
            if (!output.GetSize())
              return 0;
            continue;
          }
          else
            return parsed + cur->Avaible();
          parsed += cur->Avaible();
          to_send->Attach(cur, false);
        } while (false);
        throw_exception("Unexpected routeline");
      }
    };
    class income_serial : public income_translator
    {
      bool first
    public:
      income_serial() : first(true)
      {}
      virtual bool Parse( ax::streams::pump *const recieved, mb input, mb finished_input )
      {
        if (first)
        {
          input.AllocData();
          (input(0)->data->mes = NEW streams::pump)->Attach(recieved);
          first = false;
        }
        return false;
      }
      ~income_serial()
      {
        if (!first)
          input(0)->data->mes->End();
      }
    };
  };
};

#endif