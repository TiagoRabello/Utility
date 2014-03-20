#ifndef _UTILITY_FUNCITONAL_H
#define _UTILITY_FUNCITONAL_H

namespace Functor
{

  struct Increment_t
  {
    template< typename T >
    auto operator()( T&& value ) const -> decltype( ++( std::forward< T >( value ) ) )
    {
      return ++( std::forward< T >( value ) );
    }
  };
  constexpr Increment_t Increment{};

  struct Decrement_t
  {
    template< typename T >
    auto operator()( T&& value ) const -> decltype( --( std::forward< T >( value ) ) )
    {
      return --( std::forward< T >( value ) );
    }
  };
  constexpr Decrement_t Decrement{};

  struct Add_t
  {
    template< typename T, typename U >
    auto operator()( T&& lhs, U&& rhs ) -> decltype( std::forward< T >( lhs ) + std::forward< U >( rhs ) )
    {
      return std::forward< T >( lhs ) + std::forward< U >( rhs ); 
    }
  };
  constexpr Add_t Add{};

  struct Subtract_t
  {
    template< typename T, typename U >
    auto operator()( T&& lhs, U&& rhs ) -> decltype( std::forward< T >( lhs ) - std::forward< U >( rhs ) )
    {
      return std::forward< T >( lhs ) - std::forward< U >( rhs ); 
    }
  };
  constexpr Subtract_t Subtract{};
}

#endif
