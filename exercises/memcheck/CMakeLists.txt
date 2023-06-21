# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( memcheck LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Create the user's library.
add_library( memcheckPoly "Polygons.hpp" "Polygons.cpp" )
set_target_properties( memcheckPoly PROPERTIES OUTPUT_NAME "poly" )
if( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC" )
   target_compile_definitions( memcheckPoly PRIVATE _USE_MATH_DEFINES )
endif()

# Create the user's executable.
add_executable( memleak "memleak.cpp" )
target_link_libraries( memleak PRIVATE memcheckPoly )

# Create the "solution library".
add_library( memcheckPolySol EXCLUDE_FROM_ALL "solution/Polygons.sol.hpp" "solution/Polygons.sol.cpp" )
set_target_properties( memcheckPolySol PROPERTIES OUTPUT_NAME "polysol" )
if( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC" )
   target_compile_definitions( memcheckPolySol PRIVATE _USE_MATH_DEFINES )
endif()

# Create the "solution executable".
add_executable( memleak.sol EXCLUDE_FROM_ALL "solution/memleak.sol.cpp" )
target_link_libraries( memleak.sol PRIVATE memcheckPolySol )
add_dependencies( solution memleak.sol )
