#ifndef _BINARY_H
#define _BINARY_H

#include <Utility/Types.h>

// Returns bits masked by a given mask.
template< typename T > T Masked( T bits, T mask ) noexcept = delete;

// Returns a number on the range [ 0.0, 1.0 ] where 1.0 corresponds
// to the maximum number representable with given mask.
// 
// Works only with mask of contiguous bits.
template< typename T > float MaskedAndNormalized( T bits, T mask ) noexcept = delete;

// Byte_t Specializations.
template<> Byte_t Masked             ( Byte_t bits, Byte_t mask ) noexcept;
template<> float  MaskedAndNormalized( Byte_t bits, Byte_t mask ) noexcept;

// Word_t Specializations.
template<> Word_t Masked             ( Word_t bits, Word_t mask ) noexcept;
template<> float  MaskedAndNormalized( Word_t bits, Word_t mask ) noexcept;

// DWord_t Specializations.
template<> DWord_t Masked             ( DWord_t bits, DWord_t mask ) noexcept;
template<> float   MaskedAndNormalized( DWord_t bits, DWord_t mask ) noexcept;

// DWordLong_t Specializations.
template<> DWordLong_t Masked             ( DWordLong_t bits, DWordLong_t mask ) noexcept;
template<> float       MaskedAndNormalized( DWordLong_t bits, DWordLong_t mask ) noexcept;

#include "Detail/Binary.inl"

#endif
