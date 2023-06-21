# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( loopsRefsAuto LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Create the user's executable.
add_executable( loopsRefsAuto "loopsRefsAuto.cpp" )

# Create the "solution executable".
add_executable( loopsRefsAuto.sol EXCLUDE_FROM_ALL "solution/loopsRefsAuto.sol.cpp" )
add_dependencies( solution loopsRefsAuto.sol )
