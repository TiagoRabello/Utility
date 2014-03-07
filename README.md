## Features

* Basic Concept machinery.
* Endianess related functions.
* Perfect forwarding functors of some operators.
* Implementation of some features proposed for future iterations of std ( Apply, IndexSequence, MakeUnique ).

## Prerequisites

* A C++11 compliant compiler and standard library.
* CMake

## Adding Utility to your Project

1. Clone this repository into a subfolder of your project.

    ```
    git clone git://github.com/TiagoRabello/Utility.git
    ```
2. Add the repository as a subfolder on CMake.

    ```
    ADD_SUBDIRECTORY( Utility )
    ```
3. Set Utility include directories

    ```
    INCLUDE_DIRECTORIES( ${UTILITY_INCLUDE_DIRS} )
    ```
4. Use it!
    ```c++
    #include <Utility/Concept.h>

    template< typename T, Concept::Requires< Concept::Integral< T > >... >
    T Increment( T val )
    {
      return ++val;
    }
    ```
