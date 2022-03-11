
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( modern_oo LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Create the user's executable.
add_executable( particles "particles.cpp" )

# Create the "solution executable".
add_executable( particles.sol EXCLUDE_FROM_ALL "solution/particles.sol.cpp" )
add_dependencies( solution particles.sol )
