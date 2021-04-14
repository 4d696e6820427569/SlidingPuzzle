// eight_puzzle_main.cpp : Defines the entry point for the application.
//

#define _CRTDBG_MAP_ALLOC
#define DEBUG 1
#include <stdlib.h>
#include <crtdbg.h>

#include "./Controller/puzzle_controller.h"
#include "./Model/search_breadth_first.h"
#include "./Model/isearch.h"
#include "./Model/search_depth_first.h"
#include "./Model/utils.hpp"

int main()
{
	{
		Board b(3);
		PuzzleController controller(&b, new Dfs());
		/*ISearch* init_strategy = new Bfs();
		controller.SetStrategy(init_strategy);*/

		printf("%s\n", b.CurrentBoardToString().c_str());
		controller.Solve();

		

		//if (DEBUG) Test::RunAllTests();
		//printf("%llu\n", sizeof(Board));
	}
	if (DEBUG) _CrtDumpMemoryLeaks();
	return 0;
}
