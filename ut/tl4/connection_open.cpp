#include "tl4_tests.h"

using namespace ax::tl4;

ut::connection_open::connection_open() : unit_test("Open connection")
{
}

bool ut::connection_open::Test()
{
  network n = CreateSubNetwork(ax::units::real_timestamp());
  //connection c = n.OpenConnection("google.com", 80);
  return true;
}