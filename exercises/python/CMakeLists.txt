# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( python LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )

# Find Python for the build.
find_package( Python3 COMPONENTS Development REQUIRED )

# Build the C++ shared library.
add_library( mandel SHARED Complex.hpp mandel.hpp mandel.cpp )

# Build a "C wrapper" around the C++ shared library.
add_library( mandelc SHARED mandel_cwrapper.hpp mandel_cwrapper.cpp )
target_link_libraries( mandelc PUBLIC mandel )

# Build the Python module around the C++ shared library.
add_library( mandelm SHARED mandel_module.cpp )
target_link_libraries( mandelm PRIVATE Python3::Python mandel )
set_target_properties( mandelm PROPERTIES
   PREFIX ""
   OUTPUT_NAME "mandel" )
