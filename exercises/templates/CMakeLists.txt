# Set up the project.
cmake_minimum_required( VERSION 3.12 )
project( templates LANGUAGES CXX )

# Set up the compilation environment.
include( "${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake" )
set(CMAKE_CXX_STANDARD 20)

# Create the user's executable.
add_executable( playwithsort "Complex.hpp" "OrderedVector.hpp" "playwithsort.cpp" )

# Create the "solution executable".
add_executable( playwithsort.sol EXCLUDE_FROM_ALL
   "Complex.hpp" "solution/OrderedVector.sol.hpp" "solution/playwithsort.sol.cpp" )
target_include_directories( playwithsort.sol PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" )
add_dependencies( solution playwithsort.sol )
