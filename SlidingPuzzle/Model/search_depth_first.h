/*
* Implementation of depth first search alogrithm.
*
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_

#include <stack>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>

#include "move.hpp"
#include "utils.hpp"

class Dfs : public ISearch
{
public:
	Dfs() = default;

	void Execute(Board * b)
	{
		std::stack<State*> states_stack;
		std::vector<State*> visited;
		
		states_stack.push(new State(*b));

		std::vector<State*>* cur_possible_states;
		
		while (!states_stack.empty()) {		
			//printf("Stack size: %d\n", static_cast<int>(states_stack.size()));
			State* front_state = states_stack.top();

			states_stack.pop();

			visited.push_back(front_state);
			
			State* cur_state;
			State* cur_visited_state = nullptr;
			if (front_state->IsGoalState(*b)) {
				printf("Total moves: %d\n", front_state->TotalMoves().size());
				break;
			}
			else {
				cur_possible_states = front_state->GetPossibleStates();

				// Check for visited states. If they are visited, don't add it to the stack.
				for (std::vector<State*>::iterator it1 = cur_possible_states->begin();
					it1 != cur_possible_states->end(); ++it1) {

					cur_state = *it1;
					bool IsVisited = false;
					for (const auto cur_visited_state : visited) {
						if (*cur_visited_state == *cur_state) {
							IsVisited = true;
							break;
						}
					}

					if (!IsVisited) states_stack.push(cur_state);
				}
			}
		}

		// Clean up.
		//DeleteObjectsVector(*cur_possible_states);
		//DeleteObjectsVector(visited);
	}

};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_