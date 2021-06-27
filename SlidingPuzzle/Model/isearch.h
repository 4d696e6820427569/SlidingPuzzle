#ifndef SLIDING_PUZZLE_MODEL_ISEARCH_H_
#define SLIDING_PUZZLE_MODEL_ISEARCH_H_

#include <memory>

#include "state.h"

using std::shared_ptr;

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

	virtual void Execute(shared_ptr<State>& b) = 0;

	virtual unsigned long GetSolutionPathLength() { return solution_path_length_; }
	virtual unsigned long GetSolutionCost() { return solution_cost_; }
	virtual unsigned long GetTime() { return time_; }
	virtual unsigned long GetMaxQueueSize() { return queue_size_; }

	void ResetStats()
	{
		solution_path_length_ = 0;
		solution_cost_ = 0;
		time_ = 0;
		queue_size_ = 0;
		solution_found_ = false;
	}

protected:
	unsigned long	solution_path_length_;
	unsigned long	solution_cost_;
	unsigned long	time_;
	unsigned long	queue_size_;
	bool			solution_found_;
};

#endif // EIGHT_PUZZLE_MODEL_ISEARCH_H_