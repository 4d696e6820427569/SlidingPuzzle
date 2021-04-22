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
#include <set>

#include "move.hpp"
#include "utils.hpp"
#include "isearch.h"

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
		State* front_state = nullptr;
		
		while (!states_stack.empty()) {		
			//printf("Stack size: %d\n", static_cast<int>(states_stack.size()));
			front_state = states_stack.top();

			states_stack.pop();

			visited.insert(front_state->GetStateId());
			
			State* cur_state;
			State* cur_visited_state = nullptr;
			if (front_state->IsGoalState()) {
				this->solution_path_length_ = front_state->TotalMoves().size();
				printf("Total moves: %d\n", this->solution_path_length_);
				printf("Final state: \n");
				printf("%s\n", front_state->CurrentStateToString().c_str());
				delete front_state;
				break;
			}
			else {
				bool states_to_free[4] = { true, true, true, true };
				cur_possible_states = front_state->GetPossibleStates();

				// Check for visited states. If they are visited, don't add it to the stack.
				for (int i = 0; i < cur_possible_states->size(); i++) {

					cur_state = cur_possible_states->at(i);

					auto cur_visited_state = visited.find(cur_state->GetStateId());
					if (cur_visited_state != visited.end()) {

					}
					else {
						states_stack.push(cur_state);
						if (states_stack.size() > this->queue_size_) this->queue_size_ = states_stack.size();
						states_to_free[i] = false;
					}
				}

				for (int i = 0; i < cur_possible_states->size(); i++) {
					if (states_to_free[i]) delete cur_possible_states->at(i);
				}
				delete cur_possible_states;
			}
			delete front_state;
		}

		this->solution_cost_ = 0;
		
		auto finish = std::chrono::high_resolution_clock::now();
		this->solution_cost_ = 0;
		this->time_ = std::chrono::duration_cast<sec>(finish - start).count();

		// Clean up.
		//DeleteObjectsVector(*cur_possible_states);
		//DeleteObjectsVector(visited);
		// Clean up.
		
		State* tmp = nullptr;
		while (!states_stack.empty()) {
			tmp = states_stack.top();
			states_stack.pop();
			delete tmp;
		}
	}

};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_