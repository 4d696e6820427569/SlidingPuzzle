/*
* Implementation of breadth first search alogrithm.
* 
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_

#include <queue>
#include <list>

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
		std::list<State*> visited;

		// Mark the current state as visited.

		State* init_state = new State(*b);
		visited.push_back(init_state);
		states_queue.push(init_state);

		std::vector<State*>* cur_possible_states = nullptr;
		State* cur_state = nullptr;
		State* cur_visited_state = nullptr;

		while (!states_queue.empty()) {
			printf("Queue size: %d\n", static_cast<int>(states_queue.size()));
			State* front_state = states_queue.front();

			states_queue.pop();

			if (front_state->IsGoalState(*b)) {
				printf("Total moves: %d\n", front_state->TotalMoves().size());
				break;
			}
			else {
				cur_possible_states = front_state->GetPossibleStates();

				for (std::vector<State*>::iterator it1 = cur_possible_states->begin();
					it1 != cur_possible_states->end(); ++it1) {

					cur_state = *it1;

					// Check if it's already visited. If it is, don't add it to the queue.
					for (std::list<State*>::iterator it2 = visited.begin();
						it2 != visited.end(); ++it2) {
						cur_visited_state = *it2;
						
						if (*cur_visited_state == *cur_state) {
							
						}
						else {
							visited.push_back(cur_state);
							states_queue.push(cur_state);
						}
					}
				}
			}
		}

		// Clean up.
		//DeleteObjectsVector(*cur_possible_states);
		//DeleteObjectsVector(visited);
	}

private:
};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_