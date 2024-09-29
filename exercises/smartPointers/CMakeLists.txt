# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( smartPointers LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )
set( CMAKE_CXX_STANDARD 20 )

# Create the user's executable.
add_executable( problem1 "problem1.cpp" )
add_executable( problem2 "problem2.cpp" )
add_executable( problem3 "problem3.cpp" )
add_executable( problem4 "problem4.cpp" )
add_executable( problem5 "problem5.cpp" )

# Create the "solution executables".
add_executable( problem1.sol EXCLUDE_FROM_ALL "solution/problem1.sol.cpp" )
add_executable( problem2.sol EXCLUDE_FROM_ALL "solution/problem2.sol.cpp" )
add_executable( problem3.sol EXCLUDE_FROM_ALL "solution/problem3.sol.cpp" )
add_executable( problem4.sol EXCLUDE_FROM_ALL "solution/problem4.sol.cpp" )
add_executable( problem5.sol EXCLUDE_FROM_ALL "solution/problem5.sol.cpp" )
add_dependencies( solution problem1.sol problem2.sol problem3.sol problem4.sol problem5.sol )
