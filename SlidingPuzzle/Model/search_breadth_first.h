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
		// Need a way to store state.
		std::queue<Move>* moves_queue = new std::queue<Move>();
		
		while (!moves_queue->empty()) {
			Move front_move = moves_queue->front();
			moves_queue->pop();


		}
	}

private:
};
#endif // EIGHT_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_