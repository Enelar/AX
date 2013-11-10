#include <ax/stream/duct.h>
#include "stream_tests.h"

using namespace ut;

void make_stream_tests()
{
  unit_test *t;
  printf("==Stream subsystem testing\n");
  MAKE_TEST(t, duct_compiling);
}


namespace ut
{
  duct_compiling::duct_compiling( ) : unit_test("Testing base compiling Duct")
  {
  }

  bool duct_compiling::Test( void )
  {
    return true;
  }
};