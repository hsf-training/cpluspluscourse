
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( race LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Figure out how to use the platform's thread capabilities.
find_package( Threads REQUIRED )

# Create the user's executable.
add_executable( condition_variable condition_variable.cpp )
target_link_libraries( condition_variable PRIVATE Threads::Threads )

# Create the "solution executable".
add_executable( condition_variable EXCLUDE_FROM_ALL solution/condition_variable.sol.cpp )
target_link_libraries( condition_variable.sol PRIVATE Threads::Threads )
