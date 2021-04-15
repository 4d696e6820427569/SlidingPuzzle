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
		printf("Extremely easy problem:\n");
		Board b(3, true);
		PuzzleController controller(&b, new Bfs());
		printf("%s\n", b.CurrentBoardToString().c_str());
		controller.Solve();

		/// <summary>
		/// EZ Problem
		/// </summary>
		/// <returns></returns>
		int** ez = new int*[3];
		for (int i = 0; i < 3; i++)
			ez[i] = new int[3];


		ez[0][0] = 1;
		ez[0][1] = 2;
		ez[0][2] = 3;
		ez[1][2] = 4;
		ez[2][2] = 5;
		ez[2][1] = 6;
		ez[2][0] = 7;
		ez[1][0] = 0;
		ez[1][1] = 8;

		Board b_ez(ez, 3);
		PuzzleController controller_ez(&b_ez, new Bfs());
		printf("%s\n", b_ez.CurrentBoardToString().c_str());
		controller_ez.Solve();
		DeleteIntArray(ez, 3);

		/// <summary>
		/// EZ problem 2
		/// </summary>
		/// <returns></returns>

		printf("\nAnother easy problem:\n");
		int** ez1 = new int* [3];
		for (int i = 0; i < 3; i++)
			ez1[i] = new int[3];


		ez1[0][0] = 1;
		ez1[0][1] = 3;
		ez1[0][2] = 4;
		ez1[1][2] = 2;
		ez1[2][2] = 5;
		ez1[2][1] = 0;
		ez1[2][0] = 7;
		ez1[1][0] = 8;
		ez1[1][1] = 6;

		Board b_ez1(ez1, 3);
		PuzzleController controller_ez1(&b_ez1, new Bfs());
		printf("%s\n", b_ez1.CurrentBoardToString().c_str());
		controller_ez1.Solve();
		DeleteIntArray(ez1, 3);


		/// <summary>
		/// Medium problem.
		/// </summary>
		/// <returns></returns>

		printf("\nMedium problem.\n");
		int** m = new int* [3];
		for (int i = 0; i < 3; i++)
			m[i] = new int[3];


		m[0][0] = 1;
		m[0][1] = 3;
		m[0][2] = 4;
		m[1][2] = 2;
		m[2][2] = 5;
		m[2][1] = 0;
		m[2][0] = 7;
		m[1][0] = 8;
		m[1][1] = 6;

		Board b_m(m, 3);
		PuzzleController controller_m(&b_m, new Bfs());
		printf("%s\n", b_m.CurrentBoardToString().c_str());
		controller_m.Solve();
		DeleteIntArray(m, 3);

		printf("\nHard problem.\n");
		int** h = new int* [3];
		for (int i = 0; i < 3; i++)
			h[i] = new int[3];


		h[0][0] = 5;
		h[0][1] = 6;
		h[0][2] = 7;
		h[1][2] = 8;
		h[2][2] = 1;
		h[2][1] = 2;
		h[2][0] = 3;
		h[1][0] = 4;
		h[1][1] = 0;

		Board b_h(h, 3);
		PuzzleController controller_h(&b_h, new Bfs());
		printf("%s\n", b_h.CurrentBoardToString().c_str());
		controller_h.Solve();
		DeleteIntArray(h, 3);


		printf("\nRandom problem.\n");
		
		Board b_random(3, false);
		PuzzleController controller_random(&b_random, new Bfs());
		printf("%s\n", b_random.CurrentBoardToString().c_str());
		controller_random.Solve();
		DeleteIntArray(h, 3);


		//if (DEBUG) Test::RunAllTests();
		//printf("%llu\n", sizeof(Board));
	}
	if (DEBUG) _CrtDumpMemoryLeaks();
	return 0;
}
