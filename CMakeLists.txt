# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("SlidingPuzzle")

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

# Include sub-projects.
add_subdirectory ("SlidingPuzzle" "./build/SlidingPuzzle")
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/SlidingPuzzle/Fonts/
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/build/SlidingPuzzle/Fonts/)
