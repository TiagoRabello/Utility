#ifndef _ENDIANNESS_H
#define _ENDIANNESS_H

#include <Utility/Types.h>

// TODO: Think of a better solution to determine at compile time host endianess.
//       Maybe Boost.Endian ?
constexpr bool HostIsLittleEndian = true;
constexpr bool HostIsBigEndian    = false;

// Deleted for every type without explicit specialization.
template< typename T > T HostToLittle( T value ) noexcept = delete;
template< typename T > T HostToBig   ( T value ) noexcept = delete;
template< typename T > T LittleToHost( T value ) noexcept = delete;
template< typename T > T BigToHost   ( T value ) noexcept = delete;

// Word_t Specializations.
template<> Word_t HostToLittle( Word_t value ) noexcept;
template<> Word_t HostToBig   ( Word_t value ) noexcept;
template<> Word_t LittleToHost( Word_t value ) noexcept;
template<> Word_t BigToHost   ( Word_t value ) noexcept;

// DWord_t Specializations.
template<> DWord_t HostToLittle( DWord_t value ) noexcept;
template<> DWord_t HostToBig   ( DWord_t value ) noexcept;
template<> DWord_t LittleToHost( DWord_t value ) noexcept;
template<> DWord_t BigToHost   ( DWord_t value ) noexcept;

// DWordLong_t Specializations.
template<> DWordLong_t HostToLittle( DWordLong_t value ) noexcept;
template<> DWordLong_t HostToBig   ( DWordLong_t value ) noexcept;
template<> DWordLong_t LittleToHost( DWordLong_t value ) noexcept;
template<> DWordLong_t BigToHost   ( DWordLong_t value ) noexcept;

#include "Detail/Endian.inl"

#endif
