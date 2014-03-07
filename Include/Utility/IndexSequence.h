#ifndef _UTILITY_INDEX_SEQUENCE_H
#define _UTILITY_INDEX_SEQUENCE_H

#include "Detail/IndexSequence.inl"

template< std::size_t... index >
struct IndexSequence
{
  static constexpr std::size_t Size( ) { return sizeof...( index ); }
};

// Alias to IndexSequence< 0, 1, 2, ..., N-1 >
template< std::size_t N >
using MakeIndexSequence = typename MakeIndexSequenceImpl< N >::type;

#endif
