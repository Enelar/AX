/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "mutex_fabric.h"
#include "windows_mutex.h"

using namespace ax::threads;

abstract_mutex *mutex_fabric::CreateDefault()
{
  return NEW windows_mutex();
}

template<>
ax::threads::abstract_mutex *ax::structs::InitSingletone()
{
  return ax::threads::mutex_fabric::CreateDefault();
}