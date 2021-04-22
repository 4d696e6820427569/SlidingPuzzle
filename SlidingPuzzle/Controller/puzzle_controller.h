#ifndef SLIDING_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_
#define SLIDING_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_

#include <unordered_map>

#include "../Model/state.h"
#include "../Model/isearch.h"

class PuzzleController
{
public:
	PuzzleController();
	PuzzleController(State*);
	~PuzzleController();

	// Move cells according to Move object.
	void MoveBlankCell(const Move&);
	void UndoMoveBlankCell();

	// Generate new instance of the puzzle.
	//void GenerateNewBoard(int n = 3);

	// Solve the puzzle.
	void Solve();

	void SetStrategy(std::string);
	void SetState(State* s);

	std::string AvailableStrategies();
	std::string GetCurrentStrategy() {
		return cur_strategy_;
	}

private:
	State* state_;
	ISearch* strategy_;
	std::string cur_strategy_;
	std::unordered_map<std::string, ISearch*> strategies_;
};

#endif // EIGHT_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_