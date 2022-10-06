
# Set up the project.
cmake_minimum_required( VERSION  3.12 )
project( concepts LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the user's executable.
add_executable( concepts "concepts.cpp" )

# Create the "solution executable".
add_executable( concepts.sol1 EXCLUDE_FROM_ALL "solution/concepts.sol1.cpp" )
add_custom_target( solution1 )
add_dependencies( solution1 concepts.sol1 )
add_executable( concepts.sol2 EXCLUDE_FROM_ALL "solution/concepts.sol2.cpp" )
add_custom_target( solution2 )
add_dependencies( solution2 concepts.sol2 )
add_dependencies( solution concepts.sol1 concepts.sol2 )
