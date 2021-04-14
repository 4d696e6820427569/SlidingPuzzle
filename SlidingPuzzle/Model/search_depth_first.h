/*
* Implementation of depth first search alogrithm.
*
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_

#include <stack>
#include <vector>

#include "move.hpp"
#include "utils.hpp"

class Dfs : public ISearch
{
public:
	Dfs() = default;

	void Execute(Board * b)
	{
		// Need a way to store state.
		std::vector<State*> states_queue;
		std::vector<State*> cur_possible_states = State::GetPossibleStatesFromBoard(*b);
		std::vector<State*> visited;
		for (std::vector<State*>::iterator it = cur_possible_states.begin();
			it != cur_possible_states.end(); ++it)
			states_queue.push_back(*it);

		while (!states_queue.empty()) {
			State* front_state = states_queue.front();

			states_queue.erase(states_queue.begin()+0);

			visited.push_back(front_state);

			//printf("%s", front_state->ToString().c_str());

			if (front_state->IsGoalState(*b)) {
				printf("Total moves: %d\n", front_state->TotalMoves().size());
				break;
			}
			else {
				cur_possible_states = front_state->GetPossibleStates();
				for (std::vector<State*>::iterator it1 = cur_possible_states.begin();
					it1 != cur_possible_states.end(); ++it1) {

					State* cur_state = *it1;
					bool visited_state = false;

					// Check if it's already visited. If it is, don't add it to the stack.
					for (std::vector<State*>::iterator it2 = visited.begin();
						it2 != visited.end(); it2++) {
						if (**it2 == *cur_state) {
							visited_state = true;
							break;
						}
					}

					if (!visited_state) {
						states_queue.push_back(cur_state);
					}
				}
			}
		}

		// Clean up.
		DeleteObjectsVector(cur_possible_states);
		DeleteObjectsVector(visited);
	}

};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_