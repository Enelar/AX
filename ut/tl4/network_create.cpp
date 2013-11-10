#include "tl4_tests.h"

using namespace ax::tl4;

ut::network_create::network_create() : unit_test("Creating subnetwork")
{
}

bool ut::network_create::Test()
{
  network n = CreateSubNetwork(ax::units::real_timestamp());
  return true;
}