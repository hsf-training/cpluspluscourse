
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( stl LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Create the user's executable(s).
add_executable( stl_randomize "Complex.hpp" "randomize.cpp" )
add_executable( stl_randomize.nostl "Complex.hpp" "randomize.nostl.cpp" )

# Create the "solution executable".
add_executable( stl_randomize.sol EXCLUDE_FROM_ALL "Complex.hpp" "solution/randomize.sol.cpp" )
target_include_directories( stl_randomize.sol PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" )
add_dependencies( solution stl_randomize.sol )
