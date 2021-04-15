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
#include "./Tests/puzzle_tests.hpp"

int main()
{
	{
		/// <summary>
		/// Medium problem.
		/// </summary>
		/// <returns></returns>

		/*
		printf("\nRandom problem.\n");
		
		Board b_random(3, false);
		PuzzleController controller_random(&b_random, new Bfs());
		printf("%s\n", b_random.CurrentBoardToString().c_str());
		controller_random.Solve();
		DeleteIntArray(h, 3);


		*/
		if (DEBUG) Test::RunAllTests();
		//printf("%llu\n", sizeof(Board));
	}
	//if (DEBUG) _CrtDumpMemoryLeaks();
	return 0;
}
