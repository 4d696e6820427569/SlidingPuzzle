#ifndef SLIDING_PUZZLE_MODEL_ISEARCH_H_
#define SLIDING_PUZZLE_MODEL_ISEARCH_H_

class ISearch
{
public:

	ISearch()
		: solution_path_length_(0)
		, solution_cost_(0)
		, time_(0)
		, queue_size_(0) {};

	virtual ~ISearch() = default;

	virtual void Execute(Board* b) = 0;

	virtual unsigned int GetSolutionPathLength() { return solution_path_length_; }
	virtual unsigned int GetSolutionCost() { return solution_cost_; }
	virtual unsigned int GetTime() { return time_; }
	virtual unsigned int GetMaxQueueSize() { return queue_size_; }

protected:
	unsigned int solution_path_length_;
	unsigned int solution_cost_;
	unsigned int time_;
	unsigned int queue_size_;
};

#endif // EIGHT_PUZZLE_MODEL_ISEARCH_H_