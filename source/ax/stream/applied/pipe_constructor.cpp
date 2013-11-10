/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "pipe_constructor.h"

using namespace ax::streams;

void pipe_constructor::AddDuct( abstract_duct *d )
{
  throw_sassert(d, "Duct cant be NULL");
  ducts.push_back(d);
}

void pipe_constructor::CopyDuct( const abstract_duct *const d )
{
  throw_sassert(d, "Duct cant be NULL");
  CopyDuct(*d);
}

void pipe_constructor::CopyDuct( const abstract_duct &d )
{
  AddDuct(d.CopyScheme());
}

pipe_constructor::~pipe_constructor()
{
  while (ducts.size())
  {
    delete ducts.front();
    ducts.pop_front();
  }
}