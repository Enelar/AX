#include "tl4_crypt.h"

using namespace ax::streams;
using namespace ax::tl4;

pipe::default_buffer crypt::Read( word &readed, const word count)
{
  return BeforeReturn(pipe::Read(readed, count));
}

void crypt::SlowRead( ub *const &buffer, word &readed, const word count )
{
  todo(What i should do?);
}