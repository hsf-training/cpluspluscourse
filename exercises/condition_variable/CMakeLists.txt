# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( condition_variable LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Figure out how to use the platform's thread capabilities.
find_package( Threads REQUIRED )

# Create the user's executable.
add_executable( condition_variable "condition_variable.cpp" )
target_link_libraries( condition_variable PRIVATE Threads::Threads )

# Create the "solution executable".
add_executable( condition_variable.sol EXCLUDE_FROM_ALL "solution/condition_variable.sol.cpp" )
target_link_libraries( condition_variable.sol PRIVATE Threads::Threads )
add_dependencies( solution condition_variable.sol )
