# Set up the project.
cmake_minimum_required( VERSION  3.12 )
project( optional LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )
set(CMAKE_CXX_STANDARD 20)

# Create the user's executable.
add_executable( optional "optional.cpp" )

# Create the "solution executable".
add_executable( optional.sol EXCLUDE_FROM_ALL "solution/optional.sol.cpp" )
add_dependencies( solution optional.sol )
