#ifndef SLIDING_PUZZLE_MODEL_STATE_H_
#define SLIDING_PUZZLE_MODEL_STATE_H_

#include "move.hpp"
#include "board.h"

class State
{
public:
	State(const Board&, const Move&);
	State(State&, const Move&);
	State& operator=(State&);
	~State();
	bool operator==(const State&);

	static std::vector<State*> GetPossibleStatesFromBoard(Board&);
	std::vector<State*> GetPossibleStates();
	bool IsGoalState(Board& b);

	std::vector<Move> TotalMoves() { return moves_;  }

	std::string ToString();

private:
	int** board_;
	int n_;
	Point blank_;
	std::vector<Move> moves_;
};

#endif // SLIDING_PUZZLE_MODEL_STATE_H_