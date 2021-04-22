/*
* Implementation of breadth first search alogrithm.
* 
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_

#include <queue>
#include <set>
#include <chrono>

#include "state.h"
#include "utils.hpp"
#include "isearch.h"

class Bfs : public ISearch
{
public:
	Bfs() = default;

	void Execute(State* b)
	{
		using sec = std::chrono::seconds;
		auto start = std::chrono::high_resolution_clock::now();

		std::queue<State*> states_queue;
		std::set<std::string> visited;

		// Another separate set that contains state's IDs that are currently in states_queue.
		std::set<std::string> states_stack_ids;

		// Mark the current state as visited.
		State* init_state = new State(*b);
		visited.insert(init_state->GetStateId());
		states_queue.push(init_state);
		this->queue_size_ = 1;

		std::vector<State*>* cur_possible_states = nullptr;
		State* cur_state = nullptr;
		State* cur_visited_state = nullptr;

		while (!states_queue.empty()) {
			State* front_state = states_queue.front();

			states_queue.pop();

			if (front_state->IsGoalState()) {
				this->solution_path_length_ = front_state->TotalMoves().size();
				this->solution_found_ = true;
				this->PrintExecutionStats(front_state);
				delete front_state;
				break;
			}
			else {
				bool states_to_free[4] = { true, true, true, true };
				cur_possible_states = front_state->GetPossibleStates();

				for (int i = 0; i < cur_possible_states->size(); i++) {

					cur_state = cur_possible_states->at(i);

					// Check if it's already visited. If it is, don't add it to the queue.
					auto visited_it = visited.find(cur_state->GetStateId());
					if (visited_it != visited.end()) {
					}
					else {
						visited.insert(cur_state->GetStateId());
						states_queue.push(cur_state);
						if (states_queue.size() > this->queue_size_) this->queue_size_ = states_queue.size();
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


		// Stop the timer.
		auto finish = std::chrono::high_resolution_clock::now();
		this->solution_cost_ = 0;
		this->time_ = std::chrono::duration_cast<sec>(finish - start).count();

		// Clean up.
		State* tmp = nullptr;
		while (!states_queue.empty()) {
			tmp = states_queue.front();
			states_queue.pop();
			delete tmp;
		}
		if (!solution_found_) printf("Failure.\n");
	}

private:
	void Bfs::PrintExecutionStats(State* goal)
	{
		printf("Total moves: %d\n", this->solution_path_length_);
		printf("Final state: \n");
		printf("%s\n", goal->CurrentStateToString().c_str());
	}
};
#endif // SLIDING_PUZZLE_MODEL_SEARCH_BREADTH_FIRST_H_