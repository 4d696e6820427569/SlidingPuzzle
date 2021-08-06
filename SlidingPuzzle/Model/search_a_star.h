/*
* Implementation of A* search algorithm.
*
*/

#ifndef SLIDING_PUZZLE_MODEL_SEARCH_A_STAR_H_
#define SLIDING_PUZZLE_MODEL_SEARCH_A_STAR_H_

#include <queue>
#include <unordered_map>
#include <utility>  

#include "state.h"
#include "utils.hpp"
#include "isearch.h"

using std::priority_queue;
using std::unordered_map;
using std::vector;
using std::string;
using std::make_pair;

struct MisplacedTilesHeuristicStar
{
	bool operator() (const shared_ptr<State>& s1, const shared_ptr<State>& s2) const
	{
		return (s1->GetTotalCostToThisState() + s1->GetNumberOfMisplacedTiles()) >
			(s2->GetTotalCostToThisState() +
				s2->GetNumberOfMisplacedTiles());
	}
};

struct ManhattanDistancesHeuristic
{
	bool operator() (const shared_ptr<State>& s1, const shared_ptr<State>& s2) const
	{
		return (s1->GetTotalCostToThisState() + s1->SumOfManhattanDistances()) > 
			(s2->GetTotalCostToThisState() +
			s2->SumOfManhattanDistances());
	}
};

class AStarSearch : public ISearch
{
public:
	AStarSearch(bool useTwoStars): twoStars_(useTwoStars) {}

	void Execute(shared_ptr<State>& b )
	{
		this->ResetStats();
		priority_queue<shared_ptr<State>, vector<shared_ptr<State>>, MisplacedTilesHeuristicStar> 
			states_queue;

		if (twoStars_)
			priority_queue<shared_ptr<State>, vector<shared_ptr<State>>, ManhattanDistancesHeuristic> 
				states_queue;

		unordered_map<string, unsigned long long> visited_and_cost;

		// Mark the current state as visited.
		shared_ptr<State> init_state(make_shared<State>(*b));

		states_queue.emplace(init_state);
		this->queue_size_ = 1;

		vector<shared_ptr<State>> cur_possible_states;
		shared_ptr<State> cur_state = nullptr;
		
		while (!states_queue.empty()) {
			shared_ptr<State> front_state = states_queue.top();
			
			states_queue.pop();
			this->time_++;

			// Mark the state expanded.
			if (twoStars_)
				visited_and_cost.emplace(make_pair(front_state->GetStateId(), 
				front_state->GetTotalCostToThisState() + front_state->SumOfManhattanDistances()));
			else
				visited_and_cost.emplace(make_pair(front_state->GetStateId(),
					front_state->GetTotalCostToThisState() + front_state->GetNumberOfMisplacedTiles()));

			if (front_state->IsGoalState()) {
				this->solution_path_length_ = front_state->TotalMoves().size();
				this->solution_cost_ = front_state->GetTotalCostToThisState();
				this->solution_found_ = true;
				this->PrintExecutionStats(front_state);
				break;
			}
			else {
				cur_possible_states = front_state->GetPossibleStates();

				for (int i = 0; i < cur_possible_states.size(); i++) {

					cur_state = cur_possible_states.at(i);

					string cur_state_id = cur_state->GetStateId();

					double total_cost_to_cur_state = 0;
					if (twoStars_)
						total_cost_to_cur_state =
						cur_state->GetTotalCostToThisState() + cur_state->SumOfManhattanDistances();
					else
						total_cost_to_cur_state = cur_state->GetTotalCostToThisState() + cur_state->GetNumberOfMisplacedTiles();

					auto visited_it = visited_and_cost.find(cur_state->GetStateId());

					if (visited_it == visited_and_cost.end()) {
						// If it's not in the visited map.
						states_queue.push(cur_state);
					}
					else {
						// If it's in the visited map, check if the cost of the visited state is larger than
						// the expanded state's total cost. If it's larger, push the expanded state onto the stack.
						
						if (visited_it->second > total_cost_to_cur_state) {
							visited_and_cost[visited_it->first] = total_cost_to_cur_state;
							states_queue.push(cur_state);
						}
						
					}
				}

				// Update the maximum queue size.
				if (states_queue.size() > this->queue_size_) 
					this->queue_size_ = states_queue.size();

			}
			
		}

		// Clean up.
		if (!solution_found_) {
			printf("Failure.\n");
			PrintExecutionStats(nullptr);
		}
	}
private:
	bool twoStars_;
	void PrintExecutionStats(const shared_ptr<State>& goal)
	{
		printf("Total moves: %lu\n", this->solution_path_length_);
		printf("Maximum queue size: %lu\n", this->GetMaxQueueSize());
		printf("Number of nodes popped: %lu\n", this->time_);
		
		if (goal != nullptr) {
			printf("Solution cost: %lu\n", this->solution_cost_);
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
#endif // EIGHT_PUZZLE_MODEL_SEARCH_A_STAR_H_