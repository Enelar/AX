#ifndef _HEAD_H_
#define _HEAD_H_

#include "../source/ax/def.h"
#include <list>

namespace ut
{
  class unit_test
  {
  protected:
    void RegisterTest( unit_test *p );
  public:
    virtual bool Init( void ) { return true; }
    virtual bool Test( void ) = 0;
    const char *const name;
    unit_test( char *n ) : name(n)
    {
    }
    virtual ~unit_test( void )
    {
    }
  };
  extern std::list<unit_test *const> tests;
};

#define MAKE_TEST(var_name, x) var_name = NEW x; \
  printf("[%s]...", var_name->name);       \
  throw_assert(var_name->Test());                \
  printf("OK\n");                                  \
  delete var_name;
#define DECLARE_TEST(test_name)     \
class test_name : public unit_test  \
{                                   \
public:                             \
  test_name();                      \
  bool Test( void );                \
}
#endif