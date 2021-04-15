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
		Board b(3, true);
		PuzzleController controller(&b, new Bfs());
		/*ISearch* init_strategy = new Bfs();
		controller.SetStrategy(init_strategy);*/

		printf("%s\n", b.CurrentBoardToString().c_str());
		controller.Solve();

		int** m = new int*[3];
		for (int i = 0; i < 3; i++)
			m[i] = new int[3];

		m[0][0] = 1;
		m[0][1] = 2;
		m[0][2] = 3;
		m[1][2] = 4;
		m[2][2] = 5;
		m[2][1] = 6;
		m[2][0] = 7;
		m[1][0] = 0;
		m[1][1] = 8;

		Board b_(m, 3);
		PuzzleController controller_(&b_, new Dfs());

		printf("%s\n", b_.CurrentBoardToString().c_str());
		controller_.Solve();
		

		//if (DEBUG) Test::RunAllTests();
		//printf("%llu\n", sizeof(Board));
	}
	if (DEBUG) _CrtDumpMemoryLeaks();
	return 0;
}
