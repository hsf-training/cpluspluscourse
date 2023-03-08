# Set up the project.
cmake_minimum_required( VERSION  3.12 )
project( spaceship LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )
set(CMAKE_CXX_STANDARD 20)

# Create the user's executable.
add_executable( spaceship "spaceship.cpp" )

# Create the "solution executable".
add_executable( spaceship.sol EXCLUDE_FROM_ALL "solution/spaceship.sol.cpp" )
add_dependencies( solution spaceship.sol )
