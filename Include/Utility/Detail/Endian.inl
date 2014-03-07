#ifndef _ENDIAN_INL
#define _ENDIAN_INL

#include <algorithm>   // For std::reverse
#include <type_traits> // For std::integral_constant, std::true_type and std::false_type

namespace Detail
{
  template< typename T >
  T ReverseBytes( T value, std::true_type )
  {
    auto begin = reinterpret_cast< Byte_t * >( &value );
    auto end   = begin + sizeof( T );
    std::reverse( begin, end );
    return value;
  }

  template< typename T >
  T ReverseBytes( T value, std::false_type )
  {
    return value;
  }
}

//
// Word_t Specializations.
//
template<> Word_t HostToLittle( Word_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsBigEndian >::type( ) );
}

template<> Word_t HostToBig( Word_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsLittleEndian >::type( ) );
}

template<> Word_t LittleToHost( Word_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsBigEndian  >::type( ) );
}

template<> Word_t BigToHost( Word_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsLittleEndian >::type( ) );
}

//
// DWord_t Specializations.
//
template<> DWord_t HostToLittle( DWord_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsBigEndian >::type( ) );
}

template<> DWord_t HostToBig( DWord_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsLittleEndian >::type( ) );
}

template<> DWord_t LittleToHost( DWord_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsBigEndian  >::type( ) );
}

template<> DWord_t BigToHost( DWord_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsLittleEndian >::type( ) );
}

//
// DWordLong_t Specializations.
//
template<> DWordLong_t HostToLittle( DWordLong_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsBigEndian >::type( ) );
}

template<> DWordLong_t HostToBig   ( DWordLong_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsLittleEndian >::type( ) );
}

template<> DWordLong_t LittleToHost( DWordLong_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsBigEndian  >::type( ) );
}

template<> DWordLong_t BigToHost   ( DWordLong_t value ) noexcept
{
  return Detail::ReverseBytes( value, std::integral_constant< bool, HostIsLittleEndian >::type( ) );
}

#endif
