#include "tl4_tests.h"

using namespace ut;

void ut::make_tl4_tests()
{
  ut::unit_test *t;
  printf("==TL4 subsystem testing\n");
  MAKE_TEST(t, network_create);
  MAKE_TEST(t, connection_open);
}