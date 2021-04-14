/*
* Implementation of depth first search alogrithm.
*
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_

#include <stack>
#include <vector>

#include "move.hpp"

class Dfs : public ISearch
{
public:
	Dfs() = default;

	void Execute(Board * b)
	{
		std::stack<Move>* moves_stack = new std::stack<Move>();

		do {
			std::vector<Move> possible_moves = b->GetPossibleMoves();
			for (std::vector<Move>::iterator it = possible_moves.begin();
				it != possible_moves.end(); it++) {
				moves_stack->push(*it);
			}

			Move m = moves_stack->top();
			moves_stack->pop();
			b->MoveBlank(m);
		} while (!b->IsSolved());
		delete moves_stack;
	}

};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_