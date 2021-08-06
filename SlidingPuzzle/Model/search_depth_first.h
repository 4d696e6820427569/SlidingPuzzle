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
#include <unordered_set>
#include <deque>

#include "move.hpp"
#include "utils.hpp"
#include "isearch.h"

using std::unordered_set;
using std::stack;
using std::vector;
using std::string;

class Dfs : public ISearch
{
public:
	Dfs() = default;

	void Execute(shared_ptr<State>& b)
	{
		this->ResetStats();
		stack<shared_ptr<State>> states_stack;
		unordered_set<string> visited;

		// Another separate set that contains state's IDs that are currently in states_stack.
		unordered_set<string> states_stack_ids;

		states_stack.emplace(make_shared<State>(*b));
		states_stack_ids.emplace(states_stack.top()->GetStateId());
		this->queue_size_ = 1;

		vector<shared_ptr<State>> cur_possible_states;
		shared_ptr<State> front_state = nullptr;

		while (!states_stack.empty()) {

			// Pop the top state pointer.
			front_state = states_stack.top();
			states_stack.pop();
			this->time_++;

			// Need to also pop the corresponding state ID from the states_stack_ids.
			auto popping_id = states_stack_ids.find(front_state->GetStateId());
			states_stack_ids.erase(popping_id);

			// Insert into visited.
			visited.emplace(front_state->GetStateId());

			shared_ptr<State> cur_state;

			if (front_state->IsGoalState()) {
				this->solution_path_length_ = front_state->TotalMoves().size();
				this->solution_found_ = true;
				this->PrintExecutionStats(front_state);
				break;
			}
			else {
				bool states_to_free[4] = { true, true, true, true };
				cur_possible_states = front_state->GetPossibleStates();

				// Check for visited states. If they are visited, don't add it to the stack.
				for (int i = 0; i < cur_possible_states.size(); i++) {

					cur_state = cur_possible_states[i];

					auto cur_visited_state = visited.find(cur_state->GetStateId());
					auto state_id_is_on_stack = states_stack_ids.find(cur_state->GetStateId());

					// Check if it's already visited OR if it's currently on the stack.
					if (cur_visited_state != visited.end() ||
						state_id_is_on_stack != states_stack_ids.end()) {

					}
					else {
						// Push the state on the stack states.
						states_stack.push(cur_state);

						// Also push the state's ID on the stack IDs
						states_stack_ids.emplace(cur_state->GetStateId());

						// Update the maximum queue/stack size.
						if (states_stack.size() > this->queue_size_) this->queue_size_ = states_stack.size();

						// Mark this state to not be freed.
						states_to_free[i] = false;
					}
				}
			}

			this->solution_cost_ = 0;

			if (!solution_found_) {
				printf("Failure.\n");
				PrintExecutionStats(nullptr);
			}
		}
	}

private:
	void PrintExecutionStats(const shared_ptr<State>& goal)
	{
		printf("Total moves: %lu\n", this->solution_path_length_);
		printf("Maximum queue size: %lu\n", this->queue_size_);
		printf("Number of nodes popped: %lu\n", this->time_);

		if (goal != nullptr) {
			printf("Final state: \n");
			printf("%s\n", goal->CurrentStateToString().c_str());
			// Print directions.
			for (auto m : goal->TotalMoves()) {
				printf("%s, ", m.Direction().c_str());
			}
		}
		printf("\n");
	}

};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_DEPTH_FIRST_H_