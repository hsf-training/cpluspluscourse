# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( callgrind LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Create the user's executable.
add_executable( fibocrunch "fibocrunch.cpp" )

# Create the "solution executable".
add_executable( fibocrunch.sol EXCLUDE_FROM_ALL "solution/fibocrunch.sol.cpp" )
add_dependencies( solution fibocrunch.sol )
