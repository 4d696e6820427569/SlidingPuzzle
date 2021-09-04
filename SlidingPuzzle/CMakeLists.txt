# CMakeList.txt : CMake project for EightPuzzle, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SlidingPuzzle
    "main.cpp"
    "Tests/board_tests.hpp"
    "Model/isearch.h" "Model/search_breadth_first.h" "Model/utils.hpp" "Model/move.hpp" "Model/point.hpp" "Model/search_greedy_best_first.h" "Model/search_a_star.h" "Model/search_iterative_deepening.h" "Model/state.h" "Model/state.cpp" "Model/utils.cpp" "Model/search_uniform_cost.h" "Model/search_informed.h"
    "Views/iview.h" "Views/text_view.h" "Views/text_view.cpp" "Views/sdl_view.h" "Views/sdl_view.cpp" "Views/sfml_view.h" "Views/sfml_view.cpp"
    "Controller/puzzle_controller.h" "Controller/puzzle_controller.cpp")
target_link_libraries(SlidingPuzzle ${SDL2_LIBRARIES} sfml-graphics sfml-window sfml-system)

# TODO: Add tests and install targets if needed.
