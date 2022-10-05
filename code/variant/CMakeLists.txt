
# Set up the project.
cmake_minimum_required( VERSION  3.12 )
project( variant LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the user's executable.
add_executable( variant "variant.cpp" )

# Create the "solution executable".
add_executable( variant.sol1 EXCLUDE_FROM_ALL "solution/variant.sol1.cpp" )
add_dependencies( solution1 variant.sol1 )
add_executable( variant.sol2 EXCLUDE_FROM_ALL "solution/variant.sol2.cpp" )
add_dependencies( solution2 variant.sol2 )
add_dependencies( solution solution1 solution2 )
