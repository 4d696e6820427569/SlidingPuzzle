#ifndef EIGHT_PUZZLE_MODEL_ISEARCH_H_
#define EIGHT_PUZZLE_MODEL_ISEARCH_H_

class ISearch
{
public:
	virtual ~ISearch();

	virtual void Execute() = 0;

	virtual unsigned int GetSolutionPathLength() = 0;
	virtual unsigned int GetSolutionCost() = 0;
	virtual unsigned int GetTime() = 0;
	virtual unsigned int GetMaxQueueSize() = 0;

private:
	unsigned int solution_path_length_;
	unsigned int solution_cost_;
	unsigned int time_;
	unsigned int queue_size_;
};

#endif // EIGHT_PUZZLE_MODEL_ISEARCH_H_