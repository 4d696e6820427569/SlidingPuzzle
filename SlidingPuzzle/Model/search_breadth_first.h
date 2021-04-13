/*
* Implementation of breadth first search alogrithm.
* 
*/

#ifndef EIGHT_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_
#define EIGHT_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_

#include <queue>
#include "board.h"

class Bfs : public ISearch
{
public:
	Bfs() = default;

	void Execute(Board* b)
	{
		std::queue<Move>* moves_queue = new std::queue<Move>();
		
		while (!b->IsSolved()) {

		}
	}

private:
};
#endif // EIGHT_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_