
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( constness LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Create the user's executable.
add_executable( constplay "constplay.cpp" )
