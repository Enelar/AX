/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STREAMS_PIPE_CONSTRUCTOR_H_
#define _AX_STREAMS_PIPE_CONSTRUCTOR_H_

#include "..\abstract\abstract_duct.h"
#include <list>

namespace ax
{
  namespace streams
  {
    class pipe_constructor : public object
    {
      std::list<abstract_duct *> ducts;
    public:
      void AddDuct( abstract_duct * );
      void CopyDuct( const abstract_duct *const );
      void CopyDuct( const abstract_duct & );

      ~pipe_constructor();
    private:
      friend class pipe;
    };
  };
};

#endif