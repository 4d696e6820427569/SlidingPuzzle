/*
* Implementation of A* search algorithm.
*
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_A_STAR_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_A_STAR_H_

#include <queue>
#include <unordered_map>
#include <chrono>
#include <utility>  


#include "state.h"
#include "utils.hpp"
#include "isearch.h"

class ManhattanDistancesHeuristic
{
public:
	bool operator() (State* s1, State* s2)
	{
		return s1->SumOfManhattanDistances() > s2->SumOfManhattanDistances();
	}
};

class AStarSearch : public ISearch
{
public:
	AStarSearch() = default;
	void Execute( State* b)
	{
		using sec = std::chrono::seconds;
		auto start = std::chrono::high_resolution_clock::now();

		std::priority_queue<State*, std::vector<State*>, ManhattanDistancesHeuristic> states_queue;
		std::unordered_map<std::string, unsigned long> visited_and_cost;

		// Mark the current state as visited.
		State* init_state = new State(*b);
		visited_and_cost.insert(std::make_pair(init_state->GetStateId(), init_state->SumOfManhattanDistances()));

		states_queue.push(init_state);
		this->queue_size_ = 1;

		std::vector<State*>* cur_possible_states = nullptr;
		State* cur_state = nullptr;
		State* cur_visited_state = nullptr;
		
		while (!states_queue.empty()) {
			State* front_state = states_queue.top();

			states_queue.pop();

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

					// Check if it's already visited. If it is, don't add it to the queue.
					//auto visited_it = visited.find(cur_state->GetStateId());

					//auto visited_it_map = visited_and_cost.find(cur_state->GetStateId());
					//if (visited _it != visited.end()) {
					//	// If this state has been visited, check for the current expanded state's cost.
					//	// If it's less than the visited one's cost, add it to the priority queue.
					//}
					//else {
					//	visited.insert(cur_state->GetStateId());
					//	states_queue.push(cur_state);
					//	if (states_queue.size() > this->queue_size_) this->queue_size_ = states_queue.size();
					//}
					std::string cur_state_id = cur_state->GetStateId();
					unsigned long total_cost_to_cur_state = cur_state->SumOfManhattanDistances();

					auto visited_it = visited_and_cost.find(cur_state->GetStateId());

					if (visited_it == visited_and_cost.end()) {
						// If it's not in the visited map.
						visited_and_cost.insert(std::make_pair(cur_state_id, total_cost_to_cur_state));
						states_queue.push(cur_state);
						if (states_queue.size() > this->queue_size_) this->queue_size_ = states_queue.size();
						states_to_free[i] = false;
					}
					else {
						// If it's in the visited map, check if the cost of the visited state is larger than
						// the expanded state's total cost. If it's larger, push the expanded state onto the stack.
						if (visited_it->second > total_cost_to_cur_state) {
							visited_and_cost[visited_it->first] = total_cost_to_cur_state;
							states_queue.push(cur_state);
							if (states_queue.size() > this->queue_size_) this->queue_size_ = states_queue.size();
							states_to_free[i] = false;
						}
					}
				}
				
				for (int i = 0; i < cur_possible_states->size(); i++) {
					if (states_to_free[i]) delete cur_possible_states->at(i);
				}
				
				delete cur_possible_states;
			}
			delete front_state;
		}

		auto finish = std::chrono::high_resolution_clock::now();
		this->time_ = std::chrono::duration_cast<sec>(finish - start).count();

		// Clean up.
		State* tmp = nullptr;
		while (!states_queue.empty()) {
			tmp = states_queue.top();
			states_queue.pop();
			delete tmp;
		}
		if (!solution_found_) printf("Failure.\n");
	}
private:
	void AStarSearch::PrintExecutionStats(State* goal)
	{
		printf("Total moves: %lu\n", this->solution_path_length_);
		printf("Maximum queue size: %lu\n", this->GetMaxQueueSize());
		printf("Solution cost: %d\n", this->solution_cost_);
		printf("Final state: \n");
		printf("%s\n", goal->CurrentStateToString().c_str());
	}
};
#endif // EIGHT_PUZZLE_MODEL_SEARCH_A_STAR_H_