
# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( move LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Create the user's executable.
add_executable( trymove "trymove.cpp" )

# Create the "solution executable".
add_executable( trymove.sol EXCLUDE_FROM_ALL "solution/trymove.sol.cpp" )
add_dependencies( solution trymove.sol )
