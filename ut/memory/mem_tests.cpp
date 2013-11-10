#include "mem_tests.h"

void ut::make_memory_tests()
{
  unit_test *t;
  printf("==Memory subsystem testing\n");
  MAKE_TEST(t, fast_memory_alloc_dealloc);
  MAKE_TEST(t, fast_memory_copying);
}