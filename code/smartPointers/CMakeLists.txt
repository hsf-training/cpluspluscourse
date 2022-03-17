
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( smartPointers LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Create the user's executable.
add_executable( smartPointers "smartPointers.cpp" )

# Create the "solution executable".
add_executable( smartPointers.sol EXCLUDE_FROM_ALL "solution/smartPointers.sol.cpp" )
add_dependencies( solution smartPointers.sol )
