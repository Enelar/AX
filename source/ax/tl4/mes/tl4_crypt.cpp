#include "tl4_crypt.h"

using namespace ax::streams;
using namespace ax::tl4;

pipe::default_buffer crypt::Read( dword &readed, const dword count)
{
  return BeforeReturn(pipe::Read(readed, count));
}
void crypt::SlowRead( ub *const &buffer, dword &readed, const dword count )
{
  todo(What i should do?);
}