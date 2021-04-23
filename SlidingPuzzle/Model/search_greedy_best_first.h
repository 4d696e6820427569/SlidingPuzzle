/*
* Implementation of greedy best first search alogrithm.
*
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_GREEDY_BEST_FIRST_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_GREEDY_BEST_FIRST_H_


#include <queue>
#include <unordered_map>
#include <chrono>
#include <utility>  

#include "state.h"
#include "isearch.h"
#include "utils.hpp"


class MisplacedTilesHeuristic
{
public:
	bool operator() (State* s1, State* s2)
	{
		return s1->GetNumberOfMisplacedTiles() > s2->GetNumberOfMisplacedTiles();
	}
};

class GreedyBestFirst : public ISearch
{
public:
	GreedyBestFirst() = default;

	void Execute(State* b)
	{
		this->ResetStats();
		std::priority_queue<State*, std::vector<State*>, MisplacedTilesHeuristic> states_queue;

		std::unordered_map<std::string, unsigned long long> visited_and_cost;

		State* init_state = new State(*b);

		// Mark the current state as visited.
		//visited_and_cost.insert(std::make_pair(init_state->GetStateId(), init_state->GetTotalCostToThisState()));
		visited_and_cost.insert(std::make_pair(init_state->GetStateId(), init_state->GetNumberOfMisplacedTiles()));
		states_queue.push(init_state);
		this->queue_size_ = 1;

		std::vector<State*>* cur_possible_states = nullptr;
		State* cur_state = nullptr;
		State* cur_visited_state = nullptr;
		State* front_state = nullptr;

		while (!states_queue.empty()) {
			front_state = states_queue.top();
			states_queue.pop();
			this->time_++;

			// Mark the state expanded.
			visited_and_cost.insert(std::make_pair(front_state->GetStateId(), front_state->GetNumberOfMisplacedTiles()));

			if (front_state->IsGoalState()) {
				this->solution_path_length_ = front_state->TotalMoves().size();
				this->solution_cost_ = front_state->GetTotalCostToThisState();
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

					std::string cur_state_id = cur_state->GetStateId();
					//unsigned long total_cost_to_cur_state = cur_state->GetTotalCostToThisState();
					unsigned long long total_cost_to_cur_state = cur_state->GetNumberOfMisplacedTiles();

					auto visited_it = visited_and_cost.find(cur_state->GetStateId());

					if (visited_it == visited_and_cost.end()) {
						// If it's not in the map.
						// visited_and_cost.insert(std::make_pair(cur_state_id, total_cost_to_cur_state));
						states_queue.push(cur_state);
						
						states_to_free[i] = false;
					}
					else {
						// If it's in the visited map, check if the cost of the visited state is larger than
						// the expanded state's total cost. If it's larger, push the expanded state onto the stack.
						if (visited_it->second > total_cost_to_cur_state) {
							visited_and_cost[visited_it->first] = total_cost_to_cur_state;
							states_queue.push(cur_state);
							states_to_free[i] = false;
						}
					}

				}

				// Update the maximum queue size.
				if (states_queue.size() > this->queue_size_) this->queue_size_ = states_queue.size();

				// Free-ing up irrelevant states.
				for (int i = 0; i < cur_possible_states->size(); i++) {
					if (states_to_free[i]) delete cur_possible_states->at(i);
				}
				delete cur_possible_states;

			}

			delete front_state;
		}

		// Clean up.
		//DeleteObjectsVector(*cur_possible_states);
		//DeleteObjectsVector(visited);
		// Clean up.
		
		State* tmp = nullptr;
		while (!states_queue.empty()) {
			tmp = states_queue.top();
			states_queue.pop();
			delete tmp;
		}

		if (!solution_found_) {
			printf("Failure.\n");
			PrintExecutionStats(nullptr);
		}
	}

private:
	void PrintExecutionStats(State* goal)
	{
		printf("Total moves: %lu\n", this->solution_path_length_);
		printf("Maximum queue size: %lu\n", this->GetMaxQueueSize());
		printf("Number of nodes popped: %lu\n", this->time_);
		
		if (goal != nullptr) {
			printf("Solution cost: %d\n", this->solution_cost_);
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
#endif // SLIDING_PUZZLE_MODEL_SEARCH_GREEDY_BEST_FIRST_H_