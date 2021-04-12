#ifndef EIGHT_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_
#define EIGHT_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_

#include "../Model/board.h"
#include "../Model/isearch.h"

class PuzzleController
{
public:
	PuzzleController();
	PuzzleController(Board*);
	PuzzleController(Board*, ISearch*);

	// Move cells according to Move object.
	void MoveBlankCell(const Move&);
	inline void SetStrategy(ISearch&);

	inline ISearch* GetStrategy() const;

	// Generate new instance of the puzzle.
	void GenerateNewBoard(int n = 3);

private:
	Board* board_;
	ISearch* strategy_;
};

#endif // EIGHT_PUZZLE_CONTROLLER_PUZZLE_CONTROLLER_H_