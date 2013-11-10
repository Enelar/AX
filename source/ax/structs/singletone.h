/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STRUCTS_SINGLETONE_H_
#define _AX_STRUCTS_SINGLETONE_H_

#include "..\def.h"

namespace ax
{
  namespace structs
  {
    template<class tone>
    tone *InitSingletone()
    {
      return NEW tone;
    }

    template<class tone>
    void DeInitSingletone( tone * )
    {
    }

    template<class tone>
    class singletone : public object
    {
      tone *t;
    protected:
      virtual tone *Init() const
      {
        return InitSingletone<tone>();
      }
      virtual void DeInit()
      {
        DeInitSingletone<tone>(t);
      }
    public:
      singletone( tone *data = NULL ) : t(data)
      {
      }
      tone *const access( )
      {
        if (!t)
          t = Init();
        return t;
      }
      tone &operator *()
      {
        return *access();
      }
      tone *const operator()( )
      {
        return access();
      }
      tone *const operator->( )
      {
        return access();
      }
      ~singletone( )
      {
        if (!t)
          return;
        DeInit();
        delete t;
      }
    };
  }
}

#endif

/* END OF 'SINGLETONE.H' FILE */

/* End of faih_base_00 license*/