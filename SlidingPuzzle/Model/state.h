#ifndef SLIDING_PUZZLE_MODEL_STATE_H_
#define SLIDING_PUZZLE_MODEL_STATE_H_

#include "move.hpp"
#include "board.h"

class State
{
public:
	State(const Board&, const Move&);
	State(const State&, const Move&);
	State& operator=(State&);
	~State();
	bool IsVisited() { return visited_; };
	void SetVisit(bool b) { visited_ = b; }

	static std::vector<State*> GetPossibleStatesFromBoard(Board&);
	std::vector<State> GetPossibleStates();

	std::string ToString();

private:
	int** board_;
	int n_;
	Point blank_;
	bool visited_;
	std::vector<Move> moves_;
};

#endif // SLIDING_PUZZLE_MODEL_STATE_H_