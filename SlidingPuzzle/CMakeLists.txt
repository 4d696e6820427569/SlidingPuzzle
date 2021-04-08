# CMakeList.txt : CMake project for EightPuzzle, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SlidingPuzzle "main.cpp"  "Model/board.h" "Model/board.cpp"   "Model/cell.h"  "Tests/board_tests.hpp" "Model/isearch.h" "Model/bfs.h" "Views/iview.h" "Views/text_view.h" "Controller/puzzle_controller.h" "Controller/puzzle_controller.cpp" "Model/utils.cpp" "Model/utils.h")

# TODO: Add tests and install targets if needed.
