################################################
# CMake Library Constants
################################################
SET( MAIN_PRODUCT_OUTPUT_DIR "${CMAKE_CURRENT_LIST_DIR}/Product" )
SET( MAIN_INCLUDE_DIR        "${CMAKE_CURRENT_LIST_DIR}/Include" )

################################################
# Library Generation Code
################################################
CMAKE_MINIMUM_REQUIRED( VERSION 2.8.7 )
PROJECT( UtilityLibrary CXX )

SET( UtilityLibrary_VERSION_MAJOR      1 )
SET( UtilityLibrary_VERSION_MINOR      0 )
SET( UtilityLibrary_VERSION_PATCHLEVEL 0 )
SET( UtilityLibrary_VERSION "${UtilityLibrary_VERSION_MAJOR}.${UtilityLibrary_VERSION_MINOR}.${UtilityLibrary_VERSION_PATCHLEVEL}" )

################################################
# Library Compiler Flags
################################################
IF( WIN32 )

  SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX /W3" )

ELSE( WIN32 )

  SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -Werror -Wno-unknown-pragmas -Wno-missing-braces" )

ENDIF( WIN32 )

################################################
# Library Dependencies
################################################
# None

################################################
# Library Generation Configuration
################################################
# None needed since it is a header-only library.

IF( NOT CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_LIST_DIR )

  ################################################
  # Library Definitions for Inclusion
  ################################################
  SET( UTILITY_LIBRARY      ""                         CACHE STRING "Utility Library Name"              )
  SET( UTILITY_INCLUDE_DIRS ${MAIN_INCLUDE_DIR}        CACHE STRING "Utility Library Include Directory" )
  SET( UTILITY_LIBRARY_DIRS ${MAIN_PRODUCT_OUTPUT_DIR} CACHE STRING "Utility Library Product Directory" )

ENDIF( NOT CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_LIST_DIR )
