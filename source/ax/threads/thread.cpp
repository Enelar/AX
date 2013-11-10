/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "thread.h"
#include <windows.h>

using namespace ax::threads;

namespace
{
  DWORD CALLBACK thread_proc(LPVOID params)
  {
    thread *p = SER(params, thread);

    ui ret = p->function();

    p->SetDone();

    while (!p->GetDone())
      ::Sleep(1);

    delete p;
    return ret;
  }
  
  static
  class THREAD_SYSTEM
  {
  public:
    ~THREAD_SYSTEM()
    {
      ::Sleep(500); // delay before main thread garbage collector
    }
  } a;
}

thread_controller *thread::Start()
{
  synchronized(this)
  {
    throw_assert(!in_other_thread);
    in_other_thread = true;
    HANDLE h = CreateThread(0, 0, thread_proc, SER(this, void), 0, 0);
    return NEW thread_controller(*this, CAST(h, int));
  }
  dead_space();
}

void ax::threads::Sleep( uw ms )
{
  ::Sleep(ms);
}

void thread::Sleep( uw ms )
{
  ax::threads::Sleep(ms);
}

void thread::WaitForWord( uw count, uw recheck_ms )
{
  while (from_owner.Count() < count)
  {
    Sleep(recheck_ms);
    if (from_owner.GetDone())
      return;
  }
}