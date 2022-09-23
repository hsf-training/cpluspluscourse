
# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( race LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Figure out how to use the platform's thread capabilities.
find_package( Threads REQUIRED )

# Create the user's executable.
add_executable( racing "racing.cpp" )
target_link_libraries( racing PRIVATE Threads::Threads )

# Create the "solution executable".
add_executable( racing.sol EXCLUDE_FROM_ALL "solution/racing.sol.cpp" )
target_link_libraries( racing.sol PRIVATE Threads::Threads )
add_dependencies( solution racing.sol )
