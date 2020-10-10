#
# Small module used in every project to set up the default "compilation
# environment".
#

# Guard this file against multiple inclusions.
get_property( _compilersSet GLOBAL PROPERTY COMPILER_SETTINGS_DONE SET )
if( _compilersSet )
   unset( _compilersSet )
   return()
endif()
set_property( GLOBAL PROPERTY COMPILER_SETTINGS_DONE TRUE )


# Set up a Debug build type by default, if the user didn't ask for something
# else.
if( NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES )
   set( CMAKE_BUILD_TYPE "Debug" CACHE
        STRING "Choose the type of build." FORCE )
   set_property( CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
                 "Debug" "Release" "MinSizeRel" "RelWithDebInfo" )
endif()

# Use C++17 in the project by default, or as high of a value as possible.
set( CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard to use" )
set( CMAKE_CXX_EXTENSIONS FALSE CACHE BOOL "(Dis)Allow C++ extensions" )

# Enable (almost) all warnings for the build.
if( ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" ) OR
    ( "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" ) )
   set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra" )
elseif( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC" )
   set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4" )
endif()
