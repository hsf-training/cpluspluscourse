
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( smartPointers LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Create the user's executable.
add_executable( smartPointers smartPointers.cpp )

# Create the "solution executable".
add_executable( smartPointers.sol EXCLUDE_FROM_ALL
   solution/smartPointers.sol.cpp )
if( TARGET solution )
   add_dependencies( solution trymove.sol )
endif()
