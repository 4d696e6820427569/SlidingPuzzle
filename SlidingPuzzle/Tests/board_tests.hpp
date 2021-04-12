#ifndef BOARD_TESTS_H_
#define BOARD_TESTS_H_

#include "../Model/board.h"
#include "../Model/utils.h"
#include <assert.h>

namespace Test
{
	void BoardTest1()
	{
		Board b;
		assert(b.Size() == 3);

		printf("%s\n", b.CurrentBoardToString().c_str());
		printf("Blank position: (%d, %d)\n", b.GetBlankCoordinates().GetX(), b.GetBlankCoordinates().GetY());
		
		printf("Possible moves: \n");
		std::vector<Move> possibleMove = b.GetPossibleMoves();
		PrintMovesVector(b.GetPossibleMoves());
		b.MoveBlank(possibleMove.back());
		printf("%s\n", b.CurrentBoardToString().c_str());
		printf("Blank position: (%d, %d)\n", b.GetBlankCoordinates().GetX(), b.GetBlankCoordinates().GetY());


		printf("Solution board:\n%s\n\n", b.SolutionBoardToString().c_str());

		b = Board(5);
		assert(b.Size() == 5);

		printf("%s\n", b.CurrentBoardToString().c_str());
		printf("Blank position: (%d, %d)\n", b.GetBlankCoordinates().GetX(), b.GetBlankCoordinates().GetY());
		
		printf("Possible moves: \n");
		PrintMovesVector(b.GetPossibleMoves());

		possibleMove = b.GetPossibleMoves();
		PrintMovesVector(b.GetPossibleMoves());
		b.MoveBlank(possibleMove.back());
		printf("%s\n", b.CurrentBoardToString().c_str());
		printf("Blank position: (%d, %d)\n", b.GetBlankCoordinates().GetX(), b.GetBlankCoordinates().GetY());

		printf("Solution board:\n%s\n\n", b.SolutionBoardToString().c_str());
	}

	void BoardTest2()
	{
		Board b(4);
		printf("%s\n", b.CurrentBoardToString().c_str());
		printf("Blank position: (%d, %d)\n", b.GetBlankCoordinates().GetX(), b.GetBlankCoordinates().GetY());
		
		printf("Possible moves: \n");
		PrintMovesVector(b.GetPossibleMoves());
		std::vector<Move> possibleMove = b.GetPossibleMoves();
		PrintMovesVector(b.GetPossibleMoves());
		b.MoveBlank(possibleMove.back());
		printf("%s\n", b.CurrentBoardToString().c_str());
		printf("Blank position: (%d, %d)\n", b.GetBlankCoordinates().GetX(), b.GetBlankCoordinates().GetY());
		printf("Solution board:\n%s\n\n", b.SolutionBoardToString().c_str());
	}

	void RunBoardTests()
	{
		BoardTest1();
		BoardTest2();
	}
}

#endif BOARD_TESTS_H_