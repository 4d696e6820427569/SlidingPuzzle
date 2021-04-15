#ifndef BOARD_TESTS_H_
#define BOARD_TESTS_H_

#include "../Model/board.h"
#include "../Model/utils.hpp"
#include <assert.h>

namespace Test
{
	void ExtremelyEasyTest()
	{
		printf("Extremely easy problem:\n");
		Board b(3, true);
		PuzzleController controller(&b, new Bfs());
		printf("%s\n", b.CurrentBoardToString().c_str());
		controller.Solve();
	}

	void EasyTest()
	{
		int** ez = new int* [3];
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
		//DeleteIntArray(ez, 3);
		for (int i = 0; i < 3; i++) {
			delete[] ez[i];
		}

		delete[] ez;
	}

	void EasyTest2()
	{
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
	}

	void EasyTest3()
	{
		printf("4x4 easy problem:\n");
		Board b(4, true);
		PuzzleController controller(&b, new Bfs());
		printf("%s\n", b.CurrentBoardToString().c_str());
		controller.Solve();
	}

	void MediumTest()
	{
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
	}

	void HardTest()
	{
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
	}

	void RunTests()
	{
		ExtremelyEasyTest();
		EasyTest();
		EasyTest3();
		MediumTest();
		HardTest();
	}
}

#endif BOARD_TESTS_H_