/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#include "../def.h"
#include "utils.h"

#include "memcpy.h"

//#define _CRT_MEMORY_DEFINED
void ax::MemCpy( void *const destination, const void *const source, const sst length )
{
  ax_memcpy(destination, source, length);
}


#include <string.h>


