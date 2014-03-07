#ifndef _UTILITY_TRAITS_H
#define _UTILITY_TRAITS_H

#include <type_traits>

namespace Traits
{
  template< bool cond, typename T = void >
  using EnableIf = typename std::enable_if< cond, T >::type;

  //////////////////////////////
  // Transformation Traits.
  //////////////////////////////
  template< typename... Types > using CommonType      = typename std::common_type< Types... >::type;
  template< typename    Type  > using Decay           = typename std::decay< Type >::type;
  template< typename    Type  > using RemoveReference = typename std::remove_reference< Type >::type;
  template< typename    Type  > using RemoveCV        = typename std::remove_cv< Type >::type;

  //////////////////////////////
  // Query Traits.
  //////////////////////////////
  
  // Useful to avoid problems with universal references and copy constructor.
  //
  // Technique described by Eric Niebler:
  //   http://ericniebler.com/2013/08/07/universal-references-and-the-copy-constructo/
  template< typename Base, typename Derived > using IsSameOrDerived = std::is_base_of< Base, RemoveReference< Derived > >;

} // End of Traits namespace.

#endif
