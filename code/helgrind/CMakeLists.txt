
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( helgrind LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Figure out how to use the platform's thread capabilities.
find_package( Threads REQUIRED )

# Create the user's executable.
add_executable( fiboMT "fiboMT.cpp" )
target_link_libraries( fiboMT PRIVATE Threads::Threads )

# Create the "solution executable".
add_executable( fiboMT.sol EXCLUDE_FROM_ALL "solution/fiboMT.sol.cpp" )
target_link_libraries( fiboMT.sol PRIVATE Threads::Threads )
add_dependencies( solution fiboMT.sol )
