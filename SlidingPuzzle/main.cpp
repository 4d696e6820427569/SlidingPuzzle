// eight_puzzle_main.cpp : Defines the entry point for the application.
//

#define _CRTDBG_MAP_ALLOC
#define DEBUG 1
#include <stdlib.h>
#include <crtdbg.h>


#include "./Tests/puzzle_tests.hpp"
#include "./Controller/puzzle_controller.h"
#include "./Model/search_breadth_first.h"
#include "./Model/isearch.h"
#include "./Model/search_depth_first.h"

int main()
{
	Board b(3);
	PuzzleController controller(&b, new Dfs());
	/*ISearch* init_strategy = new Bfs();
	controller.SetStrategy(init_strategy);*/
	//controller.Solve();

	
	printf("%s\n", b.CurrentBoardToString().c_str());
	std::vector<Move> possible_moves = b.GetPossibleMoves();

	
	printf("Moving: %s\n", possible_moves.back().ToString().c_str());
	controller.MoveBlankCell(possible_moves.back());

	printf("%s\n", b.CurrentBoardToString().c_str());

	possible_moves = b.GetPossibleMoves();
	printf("Moving: %s\n", possible_moves.front().ToString().c_str());
	controller.MoveBlankCell(possible_moves.front());

	printf("%s\n", b.CurrentBoardToString().c_str());

	printf("Undoing the previous move.\n");
	controller.UndoMoveBlankCell();
	printf("%s\n", b.CurrentBoardToString().c_str());

	printf("Undoing the previous move.\n");
	controller.UndoMoveBlankCell();
	printf("%s\n", b.CurrentBoardToString().c_str());
	

	//if (DEBUG) Test::RunAllTests();
	//printf("%llu\n", sizeof(Board));
	if (DEBUG) _CrtDumpMemoryLeaks();
	return 0;
}
