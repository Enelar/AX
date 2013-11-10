/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STRUCTS_ROUND_ARRAY_H_
#define _AX_STRUCTS_ROUND_ARRAY_H_

namespace ax
{
  namespace structs
  {
    template<class type, int count>
    class round_array
    {
      type elements[count];
      uint first, last;
      bool init;

      type &Access( uint index )
      {
        return elements[Correct(index)];
      }
      type Access( uint index ) const
      {
        return elements[Correct(index)];
      }
      uint Correct( uint index ) const
      {
        if (index >= count)
          index -= count;
        throw_assert(index < count);
        return index;
      }
      uint Next( uint &index ) const
      {
        return index = Correct(index + 1);
      }
    public:
      round_array() : first(0), last(0), init(true)
      {}
      uint GetSize() const
      {
        if (init)
          return 0;
        uint ret = count + first - last;
        if (ret < count)
          return ret;
        return ret - count;
      }
      const type operator[]( uint index ) const
      {
        return Access(count + first - index);
      }

      void Push( type t )
      {
        if (init)
        {
          init = false;
          Access(first) = t;
          return;
        }

        Access(Next(first)) = t;

        if (first == last)
          Next(last);
      }

      type Pop()
      {
        throw_assert(last != first);
        type &ret = elements[last];
        if (Next(last) == first)
          init = true;
        return ret;
      }

      void FastPop( uint elements_count )
      {
        throw_assert(elements_count <= GetSize());
        last += elements_count;
        if (last >= count)
          last -= count;
      }

      type Last() const
      {
        return Access(last);
      }

      type First() const
      {
        return Access(first);
      }
    };
  };
};

#endif