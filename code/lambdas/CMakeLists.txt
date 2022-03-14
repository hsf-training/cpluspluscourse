
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( lambdas LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# This example only works warning-free in C++11 mode with MSVC and Clang.
set( CMAKE_CXX_STANDARD 11 )

# Create the user's executable.
add_executable( lambdas_randomize "Complex.hpp" "randomize.cpp" )

# Create the "solution executable".
add_executable( lambdas_randomize.sol EXCLUDE_FROM_ALL "Complex.hpp" "solution/randomize.sol.cpp" )
target_include_directories( lambdas_randomize.sol PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" )
add_dependencies( solution lambdas_randomize.sol )
