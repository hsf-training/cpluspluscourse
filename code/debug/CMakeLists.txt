
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( debug LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Create the user's executable.
add_executable( debug_randomize randomize.cpp )

# Create the "solution executable".
add_executable( debug_randomize.sol EXCLUDE_FROM_ALL
   solution/randomize.sol.cpp )
if( TARGET solution )
   add_dependencies( solution debug_randomize.sol )
endif()
