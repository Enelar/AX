#include "../def.h"
#include "utils.h"
#include <string.h>

void ax::MemMove( void *const destination, const void *const source, const sst length )
{
  if ((destination >= source && destination < (const ub *const)source + length) ||
      ((const ub *const)destination + length > source))
  
  {
    ::memmove(destination, source, length);
    return;
  }
  ax::MemCpy(destination, source, length);
}