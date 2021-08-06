#ifndef SLIDING_PUZZLE_MODEL_STATE_H_
#define SLIDING_PUZZLE_MODEL_STATE_H_

#include <vector>
#include <unordered_map>
#include <memory>

#include "move.hpp"

using std::vector;
using std::unordered_map;
using std::string;
using std::shared_ptr;
using std::make_shared;

class State
{
public:
	// Constructors section.
	State() = delete;

	// Constructor for constructing a state puzzle from a n x n
	// 2d array.
	State(int**, int);

	// Constructor for constructing a state puzzle from a
	// Board and a Move.
	//State(const Board&, const Move&);

	// Constructor for constructing a state from another state
	// with a Move.
	State(State&, const Move&);

	// Constructor for constructing a state puzzle from a
	// Board.
	State(const State&);

	State(int n = 3, bool solved = false);

	~State();

	State& operator=(State&);
	bool operator==(const State&) const;
	bool operator!=(const State&) const;
	bool operator>(const State&) const;
	bool operator<(const State&) const;

	std::vector<Move> TotalMoves() const { return moves_; }
	std::string GetStateId() const { return this->state_id_; }
	unsigned long GetCostToThisState() { return recent_move_cost_; }
	void SetCost(unsigned long c) { total_move_cost_ = c; }

	std::vector<shared_ptr<State>> GetPossibleStates();
	bool IsGoalState();
	std::string CurrentStateToString();
	unsigned long long GetTotalCostToThisState();
	int GetNumberOfMisplacedTiles();
	unsigned long long SumOfManhattanDistances();

	//static std::vector<State*>* GetPossibleStatesFromBoard();

private:
	int MoveBlank(const Move& m);
	void ReverseMove(const Move& m);
	void GenerateSolutionState();

	int n_;
	unsigned long long recent_move_cost_;
	unsigned long long total_move_cost_;
	vector<vector<int>> board_;
	vector<vector<int>> solution_;
	vector<Move> moves_;
	unordered_map<int, Point> coordinates_map_;
	Point blank_;
	string state_id_;
};

#endif // SLIDING_PUZZLE_MODEL_STATE_H_