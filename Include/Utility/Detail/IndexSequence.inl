template< std::size_t N > struct MakeIndexSequenceImpl;

template< typename T, typename U > struct FusedImpl;

template< std::size_t... index1, std::size_t... index2 >
struct FusedImpl< IndexSequence< index1... >, IndexSequence< index2... > >
{
  using type = IndexSequence< index1..., ( sizeof...( index1 ) + index2 )... >;
};

template< typename T, typename U >
using Fused = typename FusedImpl< T, U >::type;

template<>
struct MakeIndexSequenceImpl< 0 >
{
  using type = IndexSequence< >;
};

template<>
struct MakeIndexSequenceImpl< 1 >
{
  using type = IndexSequence< 0 >;
};

template< std::size_t N >
struct MakeIndexSequenceImpl
{
  using type = Fused< MakeIndexSequence< N / 2 >, MakeIndexSequence< N - N / 2 > >;
};
