#ifndef State_TESTS_H_
#define State_TESTS_H_

#include "../Model/utils.hpp"
#include "../Controller/puzzle_controller.h"
#include "../Model/isearch.h"
#include "../Model/search_breadth_first.h"
#include "../Model/search_depth_first.h"
#include "../Model/search_uniform_cost.h"
#include "../Model/search_greedy_best_first.h"
#include "../Model/search_a_star.h"
#include "../Model/search_iterative_deepening.h"

#include <assert.h>
#include <queue>
#include <iostream>

namespace Test
{
	void ExtremelyEasyTest(PuzzleController &c)
	{
		printf("Extremely easy problem:\n");
		shared_ptr<State> b(make_shared<State>(3, true));
		c.SetState(b);
		printf("%s\n", b->CurrentStateToString().c_str());
		c.Solve();
	}

	void EasyTest(PuzzleController &c)
	{
		printf("Easy problem:\n");
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

		shared_ptr<State> b_ez(make_shared<State>(ez, 3));
		//PuzzleController c(&b_ez);
		c.SetState(b_ez);
		printf("%s\n", b_ez->CurrentStateToString().c_str());
		c.Solve();
		DeleteIntArray(ez, 3);
	}

	void EasyTest2(PuzzleController& c)
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

		shared_ptr<State> b_ez1(make_shared<State>(ez1, 3));
		//PuzzleController controller_ez1(&b_ez1);
		c.SetState(b_ez1);
		printf("%s\n", b_ez1->CurrentStateToString().c_str());
		c.Solve();
		DeleteIntArray(ez1, 3);
	}

	void EasyTest4x4(PuzzleController& c)
	{
		printf("4x4 easy problem:\n");
		shared_ptr<State> b(make_shared<State>(4, true));
		//PuzzleController controller(&b);
		c.SetState(b);
		printf("%s\n", b->CurrentStateToString().c_str());
		c.Solve();
	}

	void EasyWebTest(PuzzleController& c)
	{
		printf("\nEasy web problem.\n");
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

		shared_ptr<State> b_m(make_shared<State>(m, 3));
		//PuzzleController controller_m(&b_m);
		c.SetState(b_m);
		printf("%s\n", b_m->CurrentStateToString().c_str());
		c.Solve();
		DeleteIntArray(m, 3);
	}

	void MediumWebTest(PuzzleController& c)
	{
		printf("\nMedium Web problem.\n");
		int** m = new int* [3];
		for (int i = 0; i < 3; i++)
			m[i] = new int[3];


		m[0][0] = 2;
		m[0][1] = 8;
		m[0][2] = 1;
		m[1][2] = 3;
		m[2][2] = 5;
		m[2][1] = 6;
		m[2][0] = 7;
		m[1][0] = 0;
		m[1][1] = 4;

		
		shared_ptr<State> b_m(make_shared<State>(m, 3));
		//PuzzleController controller_m(&b_m);
		c.SetState(b_m);
		printf("%s\n", b_m->CurrentStateToString().c_str());
		c.Solve();
		DeleteIntArray(m, 3);
	}

	void HardWebTest(PuzzleController& c)
	{
		printf("\nHard web problem.\n");
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

		shared_ptr<State> b_h(make_shared<State>(h, 3));
		//PuzzleController controller_h(&b_h);
		c.SetState(b_h);
		printf("%s\n", b_h->CurrentStateToString().c_str());
		c.Solve();
		DeleteIntArray(h, 3);
	}

	void ExtremelyHardProblem(PuzzleController& c)
	{
		printf("\nRandom problem.\n");
		shared_ptr<State> b_random(make_shared<State>(3, false));
		//PuzzleController controller_random(&b_random);
		c.SetState(b_random);
		printf("%s\n", b_random->CurrentStateToString().c_str());
		c.Solve();
	}

	void CustomProblem(PuzzleController& c, std::string board_str)
	{
		std::string delimiter = " ";

		board_str = trim_copy(board_str);

		printf("\nCustom problem.\n");
		int** r = new int* [3];
		for (int i = 0; i < 3; i++)
			r[i] = new int[3];

		//size_t pos = 0;
		int tokens[9];
		/*size_t i = 0;
		while ((pos = board_str.find(delimiter)) != std::string::npos) {
			tokens[i++] = board_str.substr(0, pos)[0] - '0';
			board_str.erase(0, pos + delimiter.length());
		}*/

		size_t k = 0;
		for (size_t i = 0; i < board_str.length(); i += 2) {
			tokens[k++] = board_str[i] - '0';
		}

		r[0][0] = tokens[0];
		r[0][1] = tokens[1];
		r[0][2] = tokens[2];
		r[1][2] = tokens[5];
		r[2][2] = tokens[8];
		r[2][1] = tokens[7];
		r[2][0] = tokens[6];
		r[1][0] = tokens[3];
		r[1][1] = tokens[4];

		shared_ptr<State> r_s(make_shared<State>(r, 3));
		c.SetState(r_s);
		printf("%s\n", r_s->CurrentStateToString().c_str());
		c.Solve();
	}


	void RunTests(PuzzleController &c)
	{
		//PriorityQueueComparingStates();
		/*ExtremelyEasyTest(c);
		EasyTest(c);
		EasyTest4x4(c);
		EasyWebTest(c);
		MediumWebTest(c);
		HardWebTest(c);
		ExtremelyHardProblem(c);*/
	}
}

#endif // State_TESTS_H_