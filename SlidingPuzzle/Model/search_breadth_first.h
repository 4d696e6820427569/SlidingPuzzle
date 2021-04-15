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
		std::queue<State*> states_queue;
		std::vector<State*> visited;

		// Mark the current state as visited.
		visited.push_back(new State(*b));

		std::vector<State*>* cur_possible_states = State::GetPossibleStatesFromBoard(*b);
		for (std::vector<State*>::iterator it = cur_possible_states->begin();
			it != cur_possible_states->end(); ++it) {
			states_queue.push(*it);
			visited.push_back(*it);
		}

		while (!states_queue.empty()) {
			printf("Queue size: %d\n", static_cast<int>(states_queue.size()));
			State* front_state = states_queue.front();

			states_queue.pop();

			State* cur_state;
			State* cur_visited_state = nullptr;
			if (front_state->IsGoalState(*b)) {
				printf("Total moves: %d\n", front_state->TotalMoves().size());
				break;
			}
			else {
				cur_possible_states = front_state->GetPossibleStates();

				for (std::vector<State*>::iterator it1 = cur_possible_states->begin();
					it1 != cur_possible_states->end(); ++it1) {

					cur_state = *it1;

					// Check if it's already visited. If it is, don't add it to the stack.
					for (std::vector<State*>::iterator it2 = visited.begin();
						it2 != visited.end(); it2++) {
						cur_visited_state = *it2;
						//printf("%s\n", cur_visited_state->ToString().c_str());
						if (*cur_visited_state == *cur_state) {
							//printf("A state has been visited.\n");
						}
						else {
							states_queue.push(cur_state);
						}
					}
				}

			}
		}

		// Clean up.
		DeleteObjectsVector(*cur_possible_states);
		DeleteObjectsVector(visited);
	}

private:
};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_