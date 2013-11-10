#ifndef _AX_STRUCTS_ARRAY_H_
#define _AX_STRUCTS_ARRAY_H_

#include "..\def.h"

namespace ax
{
  namespace structs
  {
    template<class type, int size>
    class array
    {
      mutable type *arr;
      inline bool IsInited()
      {
        return arr != NULL;
      }
    public:
      array() : arr(NULL)
      {
      }
      type &operator[]( uint index )
      {
        throw_assert(index < size);
        if (!IsInited())
          arr = NEW type[size];
        return arr[index];
      }
      const type &operator[]( uint index ) const
      {
        throw_assert(index < size);
        if (!IsInited())
          arr = NEW type[size];
        return arr[index];
      }
      ~array()
      {
        if (IsInited())
          delete[] arr;
      }
    };
  };
};

#endif