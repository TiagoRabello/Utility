#ifndef _BINARY_INL
#define _BINARY_INL

template<> Byte_t Masked( Byte_t bits, Byte_t mask ) noexcept
{
  return ( bits & mask );
}

template<> float MaskedAndNormalized( Byte_t bits, Byte_t mask ) noexcept
{
  return Masked( bits, mask ) / static_cast< float >( mask );
}

template<> Word_t Masked( Word_t bits, Word_t mask ) noexcept
{
  return ( bits & mask );
}

template<> float MaskedAndNormalized( Word_t bits, Word_t mask ) noexcept
{
  return Masked( bits, mask ) / static_cast< float >( mask );
}

template<> DWord_t Masked( DWord_t bits, DWord_t mask ) noexcept
{
  return ( bits & mask );
}

template<> float MaskedAndNormalized( DWord_t bits, DWord_t mask ) noexcept
{
  return Masked( bits, mask ) / static_cast< float >( mask );
}

template<> DWordLong_t Masked( DWordLong_t bits, DWordLong_t mask ) noexcept
{
  return ( bits & mask );
}

template<> float MaskedAndNormalized( DWordLong_t bits, DWordLong_t mask ) noexcept
{
  return Masked( bits, mask ) / static_cast< float >( mask );
}

#endif