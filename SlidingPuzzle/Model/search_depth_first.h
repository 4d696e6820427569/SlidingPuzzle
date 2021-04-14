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
		// Need a way to store state.
		std::stack<State>* states_queue = new std::stack<State>();
		std::vector<State*> cur_possible_states = State::GetPossibleStatesFromBoard(*b);
		for (std::vector<State*>::iterator it = cur_possible_states.begin();
			it != cur_possible_states.end(); ++it)
			states_queue->push(**it);

		while (!states_queue->empty()) {
			State front_state = states_queue->top();
			states_queue->pop();
		}
	}

};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_