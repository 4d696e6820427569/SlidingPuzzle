#ifndef SLIDING_PUZZLE_MODEL_ISEARCH_H_
#define SLIDING_PUZZLE_MODEL_ISEARCH_H_

#include "state.h"

class ISearch
{
public:

	ISearch()
		: solution_path_length_(0)
		, solution_cost_(0)
		, time_(0)
		, queue_size_(0)
		, solution_found_(false) {};

	virtual ~ISearch() = default;

	virtual void Execute(State* b) = 0;

	virtual unsigned int GetSolutionPathLength() { return solution_path_length_; }
	virtual unsigned int GetSolutionCost() { return solution_cost_; }
	virtual unsigned int GetTime() { return time_; }
	virtual unsigned int GetMaxQueueSize() { return queue_size_; }
	virtual void PrintExecutionStats() {

	}
	
	void ResetStats()
	{
		solution_path_length_ = 0;
		solution_cost_ = 0;
		time_ = 0;
		queue_size_ = 0;
		solution_found_ = false;
	}

protected:
	unsigned long solution_path_length_;
	unsigned long solution_cost_;
	unsigned long time_;
	unsigned long queue_size_;
	bool solution_found_;
};

#endif // EIGHT_PUZZLE_MODEL_ISEARCH_H_