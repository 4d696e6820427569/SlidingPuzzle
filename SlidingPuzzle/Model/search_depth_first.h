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

	void Execute(State * b)
	{
		using sec = std::chrono::seconds;
		auto start = std::chrono::high_resolution_clock::now();

		std::stack<State*> states_stack;
		std::set<std::string> visited;
		
		states_stack.push(new State(*b));
		this->queue_size_ = 1;

		std::vector<State*>* cur_possible_states;
		
		while (!states_stack.empty()) {		
			//printf("Stack size: %d\n", static_cast<int>(states_stack.size()));
			State* front_state = states_stack.top();

			states_stack.pop();

			visited.insert(front_state->GetStateId());
			
			State* cur_state;
			State* cur_visited_state = nullptr;
			if (front_state->IsGoalState()) {
				this->solution_path_length_ = front_state->TotalMoves().size();
				printf("Total moves: %d\n", this->solution_path_length_);
				break;
			}
			else {
				cur_possible_states = front_state->GetPossibleStates();

				// Check for visited states. If they are visited, don't add it to the stack.
				for (std::vector<State*>::iterator it1 = cur_possible_states->begin();
					it1 != cur_possible_states->end(); ++it1) {

					cur_state = *it1;

					auto cur_visited_state = visited.find(cur_state->GetStateId());
					if (cur_visited_state != visited.end()) {

					}
					else {
						states_stack.push(cur_state);
						if (states_stack.size() > this->queue_size_) this->queue_size_ = states_stack.size();
					}
				}
			}
		}

		this->solution_cost_ = 0;
		
		auto finish = std::chrono::high_resolution_clock::now();
		this->solution_cost_ = 0;
		this->time_ = std::chrono::duration_cast<sec>(finish - start).count();

		// Clean up.
		//DeleteObjectsVector(*cur_possible_states);
		//DeleteObjectsVector(visited);
	}

};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_