# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( operators LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Create the user's executable.
add_executable( classes "classes.cpp" )

# Create the "solution executable".
add_executable( classes_sol EXCLUDE_FROM_ALL "solution/classes_sol.cpp" )
add_dependencies( solution classes_sol )
