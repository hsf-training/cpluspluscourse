
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( polymorhism LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Create the user's library.
add_library( polymorphismPoly Polygons.hpp Polygons.cpp )
target_include_directories( polymorphismPoly PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR} )
set_target_properties( polymorphismPoly PROPERTIES OUTPUT_NAME "poly" )

# Create the user's executable.
add_executable( trypoly trypoly.cpp )
target_link_libraries( trypoly PRIVATE polymorphismPoly )

# Create the "solution executable".
add_executable( trypoly.sol EXCLUDE_FROM_ALL solution/trypoly.sol.cpp )
target_link_libraries( trypoly.sol PRIVATE polymorphismPoly )
if( TARGET solution )
   add_dependencies( solution trypoly.sol )
endif()
