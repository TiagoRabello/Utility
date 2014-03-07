#ifndef _UTILITY_MEMORY_H
#define _UTILITY_MEMORY_H

#include <memory>

template< typename Type, typename... Args >
std::unique_ptr< Type > MakeUnique( Args&&... args )
{
  return std::unique_ptr< Type >( new Type( std::forward< Args >( args )... ) );
}

#endif
