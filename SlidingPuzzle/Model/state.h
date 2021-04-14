#ifndef SLIDING_PUZZLE_MODEL_STATE_H_
#define SLIDING_PUZZLE_MODEL_STATE_H_

#include "move.hpp"
#include "board.h"

class State
{
public:
	State(const Board&, const Move&);
	State(const State&, const Move&);
	State& operator=(const State&);
	~State();
	bool IsVisited() { return visited_; };
	void SetVisit(bool b) { visited_ = b; }

private:
	int** board_;
	int n_;
	bool visited_;
	std::vector<Move>* moves_;
};

#endif // SLIDING_PUZZLE_MODEL_STATE_H_