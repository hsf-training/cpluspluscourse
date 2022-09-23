
# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( operators LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Create the user's executable.
add_executable( operators "operators.cpp" )

# Create the "solution executable".
add_executable( operators.sol EXCLUDE_FROM_ALL "solution/operators.sol.cpp" )
add_dependencies( solution operators.sol )
