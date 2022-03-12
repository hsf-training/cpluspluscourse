
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( functions LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Create the user's executable.
add_executable( functions Structs.cpp functions.cpp )

# Create the "solution executable".
add_executable( functions.sol EXCLUDE_FROM_ALL Structs.cpp solution/functions.sol.cpp )
if( TARGET solution )
   add_dependencies( solution functions.sol )
endif()
