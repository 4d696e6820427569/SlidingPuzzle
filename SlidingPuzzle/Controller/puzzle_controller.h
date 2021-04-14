#ifndef SLIDING_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_
#define SLIDING_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_

#include <stack>

#include "../Model/board.h"
#include "../Model/isearch.h"


class PuzzleController
{
public:
	PuzzleController();
	PuzzleController(Board*);
	PuzzleController(Board*, ISearch*);
	~PuzzleController();

	// Move cells according to Move object.
	void MoveBlankCell(const Move&);
	void UndoMoveBlankCell();
	inline void SetStrategy(ISearch*);

	inline ISearch* GetStrategy() const;

	// Generate new instance of the puzzle.
	void GenerateNewBoard(int n = 3);

	// Solve the puzzle.
	void Solve();

private:
	Board* board_;
	ISearch* strategy_;
	std::stack<Move>* moves_stack_;
};

#endif // EIGHT_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_