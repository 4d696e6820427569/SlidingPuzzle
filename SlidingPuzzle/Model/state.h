#ifndef SLIDING_PUZZLE_MODEL_STATE_H_
#define SLIDING_PUZZLE_MODEL_STATE_H_

#include "move.hpp"
#include "board.h"

class State
{
public:
	State();
	State(const Board&, const Move&);
	State(State&, const Move&);
	State(const Board&);
	State& operator=(State&);
	~State();
	bool operator==(const State&);
	bool operator!=(const State&);

	static std::vector<State*>* GetPossibleStatesFromBoard(Board&);
	std::vector<State*>* GetPossibleStates();
	bool IsGoalState(Board& b);

	std::vector<Move> TotalMoves() { return moves_; }

	std::string ToString();

	std::string GetStateId() { return this->state_id_; }

private:
	int** board_;
	int n_;
	std::string state_id_;
	Point blank_;
	std::vector<Move> moves_;

	void State::MoveBlank(const Move& m);
	void State::ReverseMove(const Move& m);
	
};

#endif // SLIDING_PUZZLE_MODEL_STATE_H_