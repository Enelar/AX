#include <ax/memory/mem.h>
#include "mem_tests.h"

namespace
{
  void AllocOnce( void )
  {
    ax::mem::fast_mem a(NEW ub[100], 100);
  }
  void AllocArray( void )
  {
    ax::mem::fast_mem *t[100];
    dword i;
    ub *mem;
    sst size;
    for (i = 0; i < 100; ++i)
    {
      size = rand() & 1023;
      mem = NEW ub[size];
      t[i] = NEW ax::mem::fast_mem(mem, size);
    }
    for (i = 0; i < 100; ++i)
      delete t[i];
  }
};
namespace ut
{
  fast_memory_alloc_dealloc::fast_memory_alloc_dealloc( ) : unit_test("Testing base fast memory functions : allocation, deallocation")
  {
  }

  bool fast_memory_alloc_dealloc::Test( void )
  {
    AllocOnce();
    AllocArray();
    return true;
  }
};