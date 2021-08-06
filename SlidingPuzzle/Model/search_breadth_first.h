/*
* Implementation of breadth first search alogrithm.
* 
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_

#include <queue>
#include <unordered_set>
#include <chrono>

#include "state.h"
#include "utils.hpp"
#include "isearch.h"

using std::unordered_set;
using std::queue;
using std::vector;
using std::string;

class Bfs : public ISearch
{
public:
	Bfs() = default;

	void Execute(shared_ptr<State>& b)
	{
		this->ResetStats();
		queue<shared_ptr<State>> states_queue;
		unordered_set<string> visited;

		// Another separate set that contains state's IDs that are currently in states_queue.
		unordered_set<string> states_stack_ids;

		// Mark the current state as visited.
		shared_ptr<State> init_state(make_shared<State>(*b));

		states_queue.emplace(init_state);
		this->queue_size_ = states_queue.size();

		vector<shared_ptr<State>> cur_possible_states;
		shared_ptr<State> cur_state;

		visited.emplace(init_state->GetStateId());

		while (!states_queue.empty()) {
			shared_ptr<State> front_state = states_queue.front();

			states_queue.pop();
			this->time_++;


			if (front_state->IsGoalState()) {
				this->solution_path_length_ = front_state->TotalMoves().size();
				this->solution_found_ = true;
				this->PrintExecutionStats(front_state);
				break;
			}
			else {
				cur_possible_states = front_state->GetPossibleStates();

				for (int i = 0; i < cur_possible_states.size(); i++) {

					cur_state = cur_possible_states.at(i);

					// Check if it's already visited. If it is, don't add it to the queue.
					auto visited_it = visited.find(cur_state->GetStateId());
					if (visited_it == visited.end()) {
						states_queue.emplace(cur_state);
						visited.emplace(cur_state->GetStateId());
						if (states_queue.size() > this->queue_size_) this->queue_size_ = states_queue.size();
					}
				}
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
#endif // SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_