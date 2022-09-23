# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( variadic LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the user's executable.
add_executable( variadic "variadic.cpp" )

# Create the "solution executable".
add_executable( variadic.sol EXCLUDE_FROM_ALL
   "solution/variadic.sol.cpp" )
add_dependencies( solution variadic.sol )
