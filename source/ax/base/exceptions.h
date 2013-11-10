/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_EXCEPTIONS_H_
#define _AX_EXCEPTIONS_H_

DEPRECATED
#ifdef _COMPILATOR_VC_
#define EXCEPTION(x) throw x
#endif
#define TRY DEPRECATED try
#define CATCH(t) DEPRECATED catch(t e)

#if _DEBUG_
#define throw_message(string) EXCEPTION(ax::ax_exception((string), __FILE__, __LINE__))
#else
#define throw_message(string) EXCEPTION(ax::ax_exception(NULL, __FILE__, __LINE__))
#endif

// Smart assert (with comment) //
#define throw_sassert(cond, string) if (!(cond)) throw_message("ASSERTION FAULT {" string "}"); else
// Regular assert
#define throw_assert(string) throw_sassert(string, string)

#if _DEBUG_
#define todo(ToDoMessage) throw_message("TODO: " TOSTRING(ToDoMessage))
#else
#define todo(ToDoMessage) throw_message("This function coming soon. (TODO)")
#endif

#define dead_space() throw_message("Unexpected routeline")
#define do_overload(func_with_full_namespace_address) throw_message("Overload not completed: " TOSTRING(func_with_full_namespace_address));


namespace ax
{
  class ax_exception;
  typedef bool (*exception_handler)( const ax_exception *const exception );
  typedef void (*replace_string_begin)( char *&str_where, unsigned int pass_offset, char *str_to_what );
  typedef void (*cut_filename)( char *&filename, replace_string_begin callback );
  class ax_exception
  {
    char *string;
    char *file;
    const int line;
    const int time;
  protected:
    virtual bool CallExceptionHandler( void );
    virtual void InitStrings( const char *const str, const char *const f );
    virtual void InitStrings( const int i, const char *const f );
  public:
    ax_exception( const int i, const char *const f, const int l ) : line(l), time(0)
    {
      InitStrings(i, f);
    }
    ax_exception( const char *const str, const char *const f, const int l ) : line(l), time(0)
    {
      InitStrings(str, f);
    }
    ax_exception( ax_exception &a );
    ~ax_exception( void );
    virtual const char *const GetString( void ) const;
    virtual const char *const GetFile( void ) const;
    virtual const int GetLine( void ) const;
    virtual const int GetTime( void ) const;
    static exception_handler global_handler;
    static cut_filename global_filename_replacer;
  };
};


#endif