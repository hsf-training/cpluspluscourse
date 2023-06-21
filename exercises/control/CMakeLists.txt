# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( control LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Create the user's executable.
add_executable( control "control.cpp" )

# Create the "solution executable".
add_executable( control.sol EXCLUDE_FROM_ALL "solution/control.sol.cpp" )
add_dependencies( solution control.sol )
