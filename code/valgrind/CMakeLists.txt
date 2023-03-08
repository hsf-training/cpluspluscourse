# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( valgrind LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Create the user's executable.
add_executable( valgrind_randomize "randomize.cpp" )

# Create the "solution executable".
add_executable( valgrind_randomize.sol EXCLUDE_FROM_ALL "solution/randomize.sol.cpp" )
add_dependencies( solution valgrind_randomize.sol )
