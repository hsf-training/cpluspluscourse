# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( basicTypes LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )
set( CMAKE_CXX_STANDARD 20 )

# Create the user's executable.
add_executable( basicTypes PrintHelper.h basicTypes.cpp )

# Create the "solution executable".
add_executable( basicTypes.sol EXCLUDE_FROM_ALL PrintHelper.h solution/basicTypes.sol.cpp )
target_include_directories( basicTypes.sol PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
add_dependencies( solution basicTypes.sol )
