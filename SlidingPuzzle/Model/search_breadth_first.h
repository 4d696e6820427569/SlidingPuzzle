/*
* Implementation of breadth first search alogrithm.
* 
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_

#include <queue>
#include "board.h"
#include "state.h"
#include "utils.hpp"

class Bfs : public ISearch
{
public:
	Bfs() = default;

	void Execute(Board* b)
	{
		// Need a way to store state.
		std::queue<State*> states_queue;
		std::vector<State*> cur_possible_states = State::GetPossibleStatesFromBoard(*b);
		for (std::vector<State*>::iterator it = cur_possible_states.begin();
			it != cur_possible_states.end(); ++it)
			states_queue.push(*it);
		
		while (!states_queue.empty()) {
			State* front_state = states_queue.front();
			states_queue.pop();
		}

		DeleteObjectsVector(cur_possible_states);
	}

private:
};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_