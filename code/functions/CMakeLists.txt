
# Set up the project.
cmake_minimum_required( VERSION 3.1 )
project( functions LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../CompilerSettings.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/../SolutionTarget.cmake" )

# Create the user's executable.
add_executable( functions "Structs.h" "Structs.cpp" "functions.cpp" )

# Create the "solution executable".
add_executable( functions.sol EXCLUDE_FROM_ALL "Structs.h" "Structs.cpp" "solution/functions.sol.cpp" )
target_include_directories(functions.sol PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
add_dependencies( solution functions.sol )

if( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC" )
   target_compile_definitions( functions PRIVATE _CRT_SECURE_NO_WARNINGS )
   target_compile_definitions( functions.sol PRIVATE _CRT_SECURE_NO_WARNINGS )
endif()
