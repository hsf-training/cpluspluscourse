#
# Main project for building all of the exercises at once.
#

# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( cpluspluscourse LANGUAGES CXX )

# Make sure that the project is built "out of source". As an "in source" build
# would interfere with the simple Makefiles coming with the code.
if( "${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}" )
   message( FATAL_ERROR "The tutorial code must be built out of source!" )
endif()

# Add a custom target for building all the solutions. Which are not built by
# default.
add_custom_target( solution )

# Include the test (hello world) project.
add_subdirectory( hello )

# Include the exercises that (should) work on all platforms.
add_subdirectory( functions )
add_subdirectory( loopsRefsAuto )
add_subdirectory( callgrind )
add_subdirectory( constness )
add_subdirectory( control )
add_subdirectory( cppcheck )
add_subdirectory( debug )
add_subdirectory( memcheck )
add_subdirectory( modern_oo )
add_subdirectory( move )
add_subdirectory( polymorphism )
add_subdirectory( smartPointers )
add_subdirectory( templates )
add_subdirectory( valgrind )
add_subdirectory( virtual_inheritance )
add_subdirectory( asan )

# Include the non-Windows-native exercises.
if( NOT MSVC )
   add_subdirectory( helgrind )
   add_subdirectory( python )
   add_subdirectory( race )
endif()

# Include the gcc-only exercises.
if( NOT APPLE AND NOT MSVC )
   add_subdirectory( lambdas )
   add_subdirectory( stl )
endif()
