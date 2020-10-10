
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( virtual_inheritance LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )

# Create the user's library.
add_library( textbox TextBox.hpp TextBox.cpp )
target_include_directories( textbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

# Create the user's executable.
add_executable( trymultiherit trymultiherit.cpp )
target_link_libraries( trymultiherit PRIVATE textbox )

# Create the "solution executable".
add_executable( trymultiherit.sol EXCLUDE_FROM_ALL
   solution/trymultiherit.sol.cpp )
target_link_libraries( trymultiherit.sol PRIVATE textbox )
if( TARGET solution )
   add_dependencies( solution trymultiherit.sol )
endif()
