#include "head.h"
#include "memory/mem_tests.h"
#include "tl4/tl4_tests.h"

using namespace ut;

std::list<unit_test *const> ut::tests;

void main( void )
{
  try {
  make_memory_tests();
  make_tl4_tests();
  } catch (ax::ax_exception *e)
  {
    printf("Unhandled exception %s", e->GetString());
  }
}

void unit_test::RegisterTest(ut::unit_test *p)
{
  tests.push_back(p);
}
