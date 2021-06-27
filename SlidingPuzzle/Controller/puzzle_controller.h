#ifndef SLIDING_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_
#define SLIDING_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_

#include <unordered_map>
#include <memory>

#include "../Model/state.h"
#include "../Model/isearch.h"

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::unordered_map;

class PuzzleController
{
public:
	PuzzleController();
	PuzzleController(State*);
	PuzzleController(const PuzzleController&) = delete;
	PuzzleController& operator=(const PuzzleController&) = delete;
	~PuzzleController();

	// Move cells according to Move object.
	void MoveBlankCell(const Move&);
	void UndoMoveBlankCell();

	// Generate new instance of the puzzle.
	//void GenerateNewBoard(int n = 3);

	// Solve the puzzle.
	void Solve();

	void SetStrategy(string);
	void SetState(State* s);

	string AvailableStrategies();
	string GetCurrentStrategy() const { return cur_strategy_; }

private:
	shared_ptr<State>							state_;
	shared_ptr<ISearch>							strategy_;
	string										cur_strategy_;
	unordered_map<string, shared_ptr<ISearch>>	strategies_;
};

#endif // EIGHT_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_