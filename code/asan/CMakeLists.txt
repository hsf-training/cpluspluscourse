
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( asan LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Create the user's executable.
add_executable( asan "asan.cpp" )

# Create the "solution executable".
add_executable( asan.sol EXCLUDE_FROM_ALL "solution/asan.sol.cpp" )
add_dependencies( solution asan.sol )
