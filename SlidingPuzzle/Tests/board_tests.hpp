#ifndef BOARD_TESTS_H_
#define BOARD_TESTS_H_

#include "../Model/board.h"
#include <assert.h>

namespace Test
{
	void BoardTest1()
	{
		Board b;
		assert(b.Size() == 3);

		printf("%s\n", b.ToString().c_str());

		b = Board(9);
		assert(b.Size() == 9);

		printf("%s\n", b.ToString().c_str());
	}

	void BoardTest2()
	{
		Board b(4);
		printf("%s\n", b.ToString().c_str());

		b.ReAssignBlank();
		printf("%s\n", b.ToString().c_str());

		b.ReAssignBlank();
		printf("%s\n", b.ToString().c_str());

	}

	void RunBoardTests()
	{
		BoardTest1();
		BoardTest2();
	}
}

#endif BOARD_TESTS_H_