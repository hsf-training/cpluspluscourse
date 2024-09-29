# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( race LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Figure out how to use the platform's thread capabilities.
find_package( Threads REQUIRED )

# Create the user's executable.
add_executable( racing "racing.cpp" )
target_link_libraries( racing PRIVATE Threads::Threads )

# Create the "solution executable".
add_executable( racing.sol1 EXCLUDE_FROM_ALL "solution/racing.sol1.cpp" )
target_link_libraries( racing.sol1 PRIVATE Threads::Threads )
add_dependencies( solution1 racing.sol1 )
add_executable( racing.sol2 EXCLUDE_FROM_ALL "solution/racing.sol2.cpp" )
target_link_libraries( racing.sol2 PRIVATE Threads::Threads )
add_dependencies( solution2 racing.sol2 )
add_dependencies( solution solution1 solution2 )
