#ifndef _UTILITY_TUPLE_H
#define _UTILITY_TUPLE_H

#include <Utility/IndexSequence.h>
#include <Utility/Traits.h>

#include <tuple>

namespace Concept
{
  // Types that can be used with std::get.
  template< typename T > struct Tuple;

} // End of Concept namespace.

// Calls function passing tuple elements as arguments.
template< typename Func, typename Tuple, Requires< Tuple< Traits::Decay< Tuple > > >... >
void Apply( Func&& function, Tuple&& tuple );

#include "Detail/Tuple.inl"

#endif
