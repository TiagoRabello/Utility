#ifndef _TYPES_H
#define _TYPES_H

#include <cassert>
#include <climits>
#include <cstdint>

using Byte_t      = uint8_t;
using Word_t      = uint16_t;
using DWord_t     = uint32_t;
using DWordLong_t = uint64_t;

constexpr std::size_t BitsToBytes( std::size_t numBits )
{
  assert( ( numBits % CHAR_BIT ) == 0 );
  return numBits / CHAR_BIT;
}

#endif
