# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( asan LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Create the user's executable.
add_executable( asan "asan.cpp" )

# Create the "solution executable".
add_executable( asan.sol EXCLUDE_FROM_ALL "solution/asan.sol.cpp" )
add_dependencies( solution asan.sol )
