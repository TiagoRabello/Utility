#ifndef _UTILITY_CONCEPT_H
#define _UTILITY_CONCEPT_H

#include <Utility/Traits.h>

#include <type_traits>

#include "Detail/Concept.inl"

namespace Concept
{
  /////////////////////////////
  // Basic Concepts
  /////////////////////////////

  template< typename Type > using Integral = std::is_integral< Type >;
  template< typename Type > using POD      = std::is_pod< Type >;

  /////////////////////////////
  // Concepts Aggregators
  /////////////////////////////

  // ( ( A::value && B::value && C::value && ... ) == true  ) => Inherits from std::true_type
  // ( ( A::value && B::value && C::value && ... ) == false ) => Inherits from std::false_type
  template< typename A, typename... Bs > struct All;

  // ( A::value == false ) => Inherits from std::true_type
  // ( A::value == true  ) => Inherits from std::false_type
  template< typename A > struct Not;

  /////////////////////////////
  // Concepts Checkers
  /////////////////////////////

  // Machinery used to disable functions based on requirements on types ( Concepts-like )
  //
  // Usage:
  //   tempalte< typename T, Requires< POD< T > >... > void Foo( T val );
  //
  // Technique described by R. Matrinho Fernandes:
  //   http://flamingdangerzone.com/cxx11/2012/06/01/almost-static-if.html
  template< typename... Conditions >
  using Requires = Traits::EnableIf< All< Conditions... >::value, Detail::Enabler >;

} // End of Concept namespace.

#endif
