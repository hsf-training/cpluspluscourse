# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( functions LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Create the user's executable.
add_executable(particles particles.cpp)
add_executable(particles.sol EXCLUDE_FROM_ALL
  solution/particles.sol.cpp)

if (TARGET solution)
  add_dependencies(solution particles.sol)
endif()
