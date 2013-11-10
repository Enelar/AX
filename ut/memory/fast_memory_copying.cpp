#include "../../source/ax/memory/mem.h"
#include "mem_tests.h"

using namespace ut;

fast_memory_copying::fast_memory_copying( void ) : unit_test("Copying mechanism")
{
}

namespace
{
  void CopyWhileAboveZero( const ax::mem::fast_mem &source, const dword value )
  {
    if (!value)
      return;
    ax::mem::fast_mem a(source);
    CopyWhileAboveZero(a, value - 1);
  }
};

bool fast_memory_copying::Test()
{
  ax::mem::fast_mem a(new ub[100], 100);
  CopyWhileAboveZero(a, 100);
  return true;
}