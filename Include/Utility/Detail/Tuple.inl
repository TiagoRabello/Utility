#include <Utility/IndexSequence.h>

// Used to avoid compiler warnings.
template< typename... T > void Ignore( T&&... ) {}

template< typename Func, typename Tuple, std::size_t... index >
auto ApplyImpl( Func function, Tuple&& tuple, IndexSequence< index... > )
  -> decltype( std::forward< Func >( function )( std::get< index >( std::forward< Tuple >( tuple ) )... ) ) 
{
  return std::forward< Func >( function )( std::get< index >( std::forward< Tuple >( tuple ) )... );
}

namespace Concept
{
  namespace Detail
  {
    template< typename T >
    auto IsTupleHelper(int) -> decltype( std::get< 0 >( declval< T >( ) ), std::true_type{} )

    template< typename T >
    auto IsTupleHelper(...) -> std::false_type;
  }

  template< typename T >
  struct Tuple : decltype( Detail::IsTupleHelper< T >( 0 ) ) { };

} // End of Concept namespace.

template< typename Func, typename Tuple, Requires< Concept::Tuple< Traits::Decay< Tuple > > >... >
auto Apply( Func&& function, Tuple&& tuple )
  -> decltype( ApplyImpl( std::forward< Func >( function ), std::forward< Tuple >( tuple ), MakeIndexSequence< std::tuple_size< TupleType >{} >{} ) )
{
  using MakeIndexType = MakeIndexSequence< std::tuple_size< Traits::Decay< TupleType > >::value >;

  return ApplyImpl( std::forward< Func >( function ), std::forward< Tuple >( tuple ), MakeIndexType{} );
}
