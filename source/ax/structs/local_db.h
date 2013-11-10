/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_STRUCTS_LOCAL_DB_H_
#define _AX_STRUCTS_LOCAL_DB_H_

#include "hash.h"
#include <vector>
#include "../stream/stream.h"

#define CHECK_DB return true

namespace ax
{
  namespace structs
  {
    template <typename db_data, class db_hash = dhash >
    class local_db : object
    {
    public:
      typedef typename db_hash::val_type Tpos;
      typedef typename db_hash::key_type Tid;
      typedef db_data Tdata;
      typedef db_hash Thash;

      struct entry
      {
        Tid id;
        db_data *data;

        db_data *operator->() const
        {
          throw_assert(data);
          return data;
        }

        operator db_data *() const
        {
          return data;
        }
      };

      struct translate
      {
        Tid id;
        Tpos pos;
      };

      typedef const entry &entry_refactor;

    protected:

      std::vector<entry> data_base;
      std::vector<translate> book_marks;

      Tid next_id;

      template<typename Tvalue>
      Tpos SearchFirstPostThatMoreThan( const Tvalue &value, Tpos &ret ) const
      {
        Tpos start = 0, end = book_marks.size(), cur;
        if (!end || book_marks[end - 1].id <= value)
          return false;
        while (start != end)
        {
          cur = (end - start) / 2 + start;
          if (book_marks[cur].id > value)
            end = cur;
          else
            start = cur + 1;
        }
        if (start == book_marks.size())
          return false;
        if (book_marks[start].id > value)
          if (book_marks[cur].id > value)
            return !(ret = cur) || true;
          else
            return !(ret = start) || true;
        return false;
      }

      template<typename Tvalue>
      bool SearchPosByValue( const Tvalue &value, Tpos &ret ) const
      { // вроде еще раз перепроверил...
        if (!book_marks.size())
          return false;
        Tpos t;
        if (!SearchFirstPostThatMoreThan(value, t))
          t = book_marks.size() - 1;
        else
          if (t)
            --t;
        if (book_marks[t].id == value)
        {
          ret = t;
          return true;
        }
        return false;
      }

      Tpos GetNextFreeId()
      {
        if (book_marks.size())
          while (IsIdBusy(next_id))
            ++next_id;
        return next_id;
      }
    public:
      bool IsIdBusy( const Tid id ) const
      {
        Tpos i;
        return SearchPosByValue(id, i);
      }
      bool IsPlaceBusy( const Tpos pos ) const
      {
        return pos >= 0 && pos < data_base.size();
      }
    protected:
      void InsertSort( translate &t, Tpos position )
      {
        Tpos s = book_marks.size(), i;
        throw_assert(s);
        throw_assert(s - 1 >= position);
        for (i = s - 1; i > position; --i)
          book_marks[i] = book_marks[i - 1];
        throw_assert(i == position);
        book_marks[i] = t;
      }

      bool CheckBookMarks() const
      {
        CHECK_DB;
        Tpos s = book_marks.size(), i;
        if (!s)
          return true;
        Tid id = book_marks[0].id, c;
        for (i = 1; i < s; ++i)
          if ((c = book_marks[i].id) <= id)
            return false;
          else
            id = c;
        return true;
      }

      Tpos InsertBookMark( const Tid id, const Tpos pos )
      {
        throw_assert(id);
        throw_assert(!IsIdBusy(id));
        Tpos i;
        translate t;
        t.id = id;
        t.pos = pos;
        bool pre_check = CheckBookMarks();
        if (!SearchFirstPostThatMoreThan(id, i))
        {
          book_marks.push_back(t);
          throw_assert(CheckBookMarks());
          return book_marks.size();
        }
        book_marks.push_back(t);
        InsertSort(t, i);
        throw_assert(CheckBookMarks());
        return i;
      }

    public:
      local_db() : next_id(1)
      {
      }
      /***
       * Adding records part
       ***/
      db_data *const InsertData( const db_data &data, const Tid id )
      {
        db_data *ret = NEW db_data(data);
        ImportData(ret, id);
        return ret;
      }

      db_hash ImportData( db_data *const data )
      {
        GetNextFreeId();
        return ImportData(data, next_id++);
      }

      db_hash ImportData( db_data *const data, Tid id )
      {
        db_hash ret = id;
        ret << InsertBookMark(id, data_base.size());
        entry t;
        t.data = data;
        t.id = id;
        data_base.push_back(t);
        CheckDB();
        return ret;
      }

      db_data *const AddData( const db_data &data )
      {
        db_hash t;
        return AddData(data, t);
      }

      db_data *const AddData( const db_data &data, db_hash &ha )
      {
        db_data *p = NEW db_data(data);
        ha = ImportData(p);
        return operator[](ha);
      }

      db_data *const AllocData( db_hash &ha )
      {
        db_data dummy;
        return AddData(dummy, ha);
      }

      db_data *const AllocData( void )
      {
        db_hash t;
        return AllocData(t);
      }

      /***
       * Removing records part
       ***/
      db_data *const ExcludeOrderedEntry( const Tpos bookmark_pos )
      {
        throw_assert(bookmark_pos < book_marks.size());
        throw_assert(bookmark_pos >= 0);
        return ExcludeEntry(book_marks[bookmark_pos].pos);
      }

      db_data *const ExcludeEntry( const Tpos pos )
      {
        throw_assert(pos < data_base.size());
        throw_assert(pos >= 0);
        db_data * &ref = data_base[pos].data;
        db_data *const ret = ref;
        ref = NULL;
        DeleteEntry(pos);
        return ret;
      }

      db_data *const ExcludeData( const Tid id )
      {
        db_hash t = id;
        return ExcludeData(t);
      }

      db_data *const ExcludeData( const db_hash h )
      {
        Tpos pos;
        throw_assert(GetDataPos(h, pos));
        return ExcludeEntry(pos);
      }

      void DeleteEntry( const Tpos target_bookmark_pos )
      {
        Tpos target_pos = book_marks[target_bookmark_pos].pos;
        Tid id = data_base[target_pos].id;

        delete data_base[target_pos].data;

        struct // wish it will be union... dat c++
        {
          Tpos to_last,
             to_target;
        } position_of_bookmark;
        if (target_pos == data_base.size() - 1)
          data_base.pop_back();
        else
        { // Reorganize storage
          data_base[target_pos] = data_base[data_base.size() - 1];
          data_base.pop_back();
          throw_assert(SearchPosByValue(data_base[target_pos].id, position_of_bookmark.to_last));
          Tpos bm_pos = position_of_bookmark.to_last;
          throw_assert(bm_pos < book_marks.size());

          // bm_pos - position of bookmark that will be point on free place
          // (place where element was deleted)
          // Change bookmark target
          book_marks[bm_pos].pos = target_pos;
        }
        throw_assert(SearchPosByValue(id, position_of_bookmark.to_target));
        // Move bookmarks
        if (position_of_bookmark.to_target + 1 != book_marks.size())
          ax::MemMove(
            &book_marks[position_of_bookmark.to_target],
              &book_marks[position_of_bookmark.to_target + 1],
              (book_marks.size() - 1 - position_of_bookmark.to_target) * sizeof(translate));
        book_marks.pop_back();

        CheckDB();
      }

      void DeleteData( const Tid id )
      {
        db_hash h = id;
        DeleteData(h);
      }

      void DeleteData( const db_hash &h )
      {
        Tpos pos;
        throw_assert(GetDataPos(h, pos));
        DeleteEntry(pos);
      }

      /***
       * Search records part
       ***/
    protected:
      bool GetDataPos( const Tid id, Tpos &pos ) const
      {
       db_hash h = id;
       bool ret;
       if (ret = GetDataPos(h))
         pos = h.V();
       return ret;
      }

      bool GetDataPos( const db_hash &h ) const
      {
       Tpos pos;
       if (!SearchPosByValue(h.key, pos))
         return false;
       h << book_marks[pos].pos;
       return true;
      }

      bool GetDataId( const Tpos pos, Tid &id ) const
      {
        db_hash t;
        if (!GetDataId(pos, t))
          return false;
        id = t;
        return true;
      }

      bool GetDataId( const Tpos pos, db_hash &ret ) const
      {
        throw_assert(pos >= 0);
        if (pos >= GetSize())
          return false;
        ret = data_base[pos].id;
        ret << pos;
        return true;
      }

    public:
      /***
       * Access records part
       ***/
      db_data *const operator[]( const Tid id ) const
      {
        db_hash t = id;
        return (*this)[t];
      }

      db_data *const operator[]( const db_hash &ha ) const
      {
        return GetData(ha);
      }

      db_data *const GetData( const Tid id ) const
      {
        throw_assert(id);
        db_hash h = id;
        return GetData(h);
      }

      db_data *const GetData( const db_hash &h ) const
      {
        if (GetDataPos(h))
        {
          throw_assert(h.V() < GetSize());
          return data_base[h.V()].data;
        }
        return NULL;
      }

      entry_refactor GetEntry( const Tpos pos ) const
      {
        throw_assert(pos >= 0);
        throw_sassert(pos < data_base.size(), "Position out of range");
        return data_base[pos];
      }

      entry_refactor GetEntry( const db_hash &h ) const
      {
        throw_sassert((*this)[h], "Cant found entry");
        return data_base[h.V()];
      }

      entry_refactor GetOrderedEntry( const Tpos pos ) const
      {
        db_hash h;
        h << pos;
        return GetOrderedEntry(h);
      }

      entry_refactor GetOrderedEntry( db_hash &h ) const
      {
        throw_assert(h.V() >= 0);
        throw_sassert(h.V() < data_base.size(), "Position out of range");
        translate t = book_marks[h.V()];
        h << t.pos;
        h = t.id;
        return GetEntry(h);
      }

      db_data *GetDataByPos( const Tpos pos ) const
      {
        entry_refactor e = GetEntry(pos);
        throw_assert(e);
        return e->data;
      }

      db_data *GetDataByPos( const db_hash &h ) const
      {
        entry_refactor e = GetEntry(h);
        throw_assert(e);
        return e->data;
      }

      entry_refactor operator()( const Tpos pos ) const
      {
        return GetOrderedEntry(pos);
      }

      entry_refactor operator()( db_hash &h ) const
      {
        return GetOrderedEntry(h);
      }

      /***
       * Other functions
       ***/
      dword GetSize( void ) const
      {
        return data_base.size();
      }

      dword GetIdByPos( dword pos ) const
      {
        throw_assert(pos >= 0);
        throw_assert(pos < data_base.size());
        return GetEntry(pos)->id;
      }

      ~local_db( void )
      {
        CheckDB();
        dword size = GetSize();

        while (size > 0)
        {
          size--;
          DeleteEntry(size);
        }
      }

      /***
       * Debug functions
       **/
      void Dump( ax::streams::stream &s ) const
      {
        todo(dump_local_db);
        todo(stream to std::stream);
        //DumpBookMarks(F);
        //DumpValues(F);
      }

    private:
      bool CheckDB( ) const
      {
        CHECK_DB;
        try
        {
          throw_assert(data_base.size() == book_marks.size());
          for (uint i = 0, s = book_marks.size(); i < s; ++i)
          {
            translate e = book_marks[i];
            throw_assert(e.pos < s);
            throw_assert(e.id == data_base[e.pos].id);
            throw_assert(data_base[e.pos].data);
            for (uint j = 0; j < s; ++j)
              if (e.pos != j)
                throw_assert(data_base[e.pos].data != data_base[j].data);
          }
          return true;
        } catch (ax_exception *)
        {
          return false;
        }
      }
#if 0
      void DumpBookMarks( ax::streams::stream &s ) const
      {
        dword i = 0, s = book_marks.size();
        fprintf(F, "Book marks[%li]:\nCheck sort: %s\n", unsafe_dword(s), CheckBookMarks() ? "TRUE" : "FALSE");
        for (i = 0; i < s; ++i)
          fprintf(F, "[%i] id(%i)=>%i %s\n", unsafe_dword(i), unsafe_dword(book_marks[i].id), unsafe_dword(book_marks[i].pos),
          book_marks[i].id == data_base[book_marks[i].pos].id ? "" : "ERROR!!!!!!!"
          );
      }
      void DumpValues( ax::streams::stream &s ) const
      {
        dword i = 0, s = data_base.size();
        fprintf(F, "Data Base[%li]:\n", unsafe_dword(s));
        for (i = 0; i < s; ++i)
          fprintf(F, "[%i]=>id(%i)\n", unsafe_dword(i), unsafe_dword(data_base[i].id));
      }
#endif
    };
  };
};

#endif