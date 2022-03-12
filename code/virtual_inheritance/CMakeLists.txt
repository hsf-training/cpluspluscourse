
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( virtual_inheritance LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Create the user's library.
add_library( textbox "TextBox.hpp" "TextBox.cpp" )
target_include_directories( textbox PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" )

# Create the user's executable.
add_executable( trymultiherit "trymultiherit.cpp" )
target_link_libraries( trymultiherit PRIVATE textbox )

# Create the solution's library.
add_library( textboxsol EXCLUDE_FROM_ALL "solution/TextBox.hpp" "solution/TextBox.cpp" )
target_include_directories( textboxsol PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/solution" )
add_dependencies( solution textboxsol )

# Create the "solution executable".
add_executable( trymultiherit.sol EXCLUDE_FROM_ALL "solution/trymultiherit.sol.cpp" )
target_link_libraries( trymultiherit.sol PRIVATE textboxsol )
add_dependencies( solution trymultiherit.sol )
