
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( memcheck LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Create the user's library.
add_library( memcheckPoly Polygons.hpp Polygons.cpp )
set_target_properties( memcheckPoly PROPERTIES OUTPUT_NAME "poly" )

# Create the user's executable.
add_executable( memleak memleak.cpp )
target_link_libraries( memleak PRIVATE memcheckPoly )

# Create the "solution library".
add_library( memcheckPolySol EXCLUDE_FROM_ALL
   solution/Polygons.sol.hpp solution/Polygons.sol.cpp )
set_target_properties( memcheckPolySol PROPERTIES OUTPUT_NAME "polysol" )

# Create the "solution executable".
add_executable( memleak.sol EXCLUDE_FROM_ALL solution/memleak.sol.cpp )
target_link_libraries( memleak.sol PRIVATE memcheckPolySol )
if( TARGET solution )
   add_dependencies( solution memleak.sol )
endif()
