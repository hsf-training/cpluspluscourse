#
# Main project for building all of the exercises at once.
#

# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( cpluspluscourse LANGUAGES CXX )

# Make sure that the project is built "out of source". As an "in source" build
# would interfere with the simple Makefiles coming with the code.
if( "${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}" )
   message( FATAL_ERROR "The tutorial code must be built out of source!" )
endif()

# Include the exercises that (should) work on all platforms.
add_subdirectory( hello )
add_subdirectory( asan )
add_subdirectory( basicTypes )
add_subdirectory( callgrind )
add_subdirectory( condition_variable )
add_subdirectory( constness )
add_subdirectory( control )
add_subdirectory( cppcheck )
add_subdirectory( debug )
add_subdirectory( functions )
add_subdirectory( loopsRefsAuto )
add_subdirectory( memcheck )
add_subdirectory( modern_oo )
add_subdirectory( move )
add_subdirectory( operators )
add_subdirectory( polymorphism )
add_subdirectory( race )
add_subdirectory( smartPointers )
add_subdirectory( stl )
add_subdirectory( templates )
add_subdirectory( valgrind )
add_subdirectory( variadic )
add_subdirectory( virtual_inheritance )

# Include the non-Windows-native exercises.
if( NOT MSVC )
   add_subdirectory( helgrind )
   add_subdirectory( python )
endif()
