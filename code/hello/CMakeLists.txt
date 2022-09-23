
# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( hello LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Set up the library.
add_library( helloLib "hello.hpp" "hello.cpp" )
set_target_properties( helloLib PROPERTIES OUTPUT_NAME "hello" )

# Set up the executable.
add_executable( hello "main.cpp" )
target_link_libraries( hello PRIVATE helloLib )
