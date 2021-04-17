#ifndef SLIDING_PUZZLE_MODEL_STATE_H_
#define SLIDING_PUZZLE_MODEL_STATE_H_

#include "move.hpp"
#include "board.h"

class State
{
public:
	// Constructors section.
	State();

	// Constructor for constructing a state puzzle from a n x n
	// 2d array.
	State(int**, int);

	// Constructor for constructing a state puzzle from a
	// Board and a Move.
	State(const Board&, const Move&);

	// Constructor for constructing a state from another state
	// with a Move.
	State(State&, const Move&);

	// Constructor for constructing a state puzzle from a
	// Board.
	State(const Board&);

	~State();

	State& operator=(State&);
	bool operator==(const State&);
	bool operator!=(const State&);
	bool operator>(const State&);
	bool operator<(const State&);

	std::vector<Move> TotalMoves() const { return moves_; }
	std::string GetStateId() const { return this->state_id_; }
	unsigned long GetCostToThisState() { return cost_; }
	void SetCost(unsigned long c) { cost_ = c; }

	std::vector<State*>* GetPossibleStates();
	bool IsGoalState(Board& b);
	std::string ToString();
	unsigned long GetTotalCostToThisState();

	static std::vector<State*>* GetPossibleStatesFromBoard(Board&);

private:
	unsigned long cost_;
	int** board_;
	int n_;
	Point blank_;
	std::vector<Move> moves_;
	std::string state_id_;
	
	int State::MoveBlank(const Move& m);
	void State::ReverseMove(const Move& m);
	
};

#endif // SLIDING_PUZZLE_MODEL_STATE_H_