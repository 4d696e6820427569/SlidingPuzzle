/*
* Board
* Models the 2d board in the sliding puzzle. It contains n x n cells.
*/

#ifndef EIGHT_PUZZLE_MODEL_BOARD_H_
#define EIGHT_PUZZLE_MODEL_BOARD_H_

#include <string>

#include "cell.h"

class Board
{
public:
	Board(int n = 3);
	Board(const Board& b);
	~Board();
	Board& operator = (const Board& b);

	bool operator == (const Board& b);
	inline int Size() const { return n_; }
	inline Cell* GetBlankCell() const { return blank_; }
	void GetPossibleMoves();
	std::string CurrentBoardToString();
	std::string SolutionBoardToString();

private:
	Cell** board_;
	Cell** solution_;
	Cell* blank_;
	int n_;

	void GenerateSolutionBoard();
	void PrintBoard(Cell** b);
};

#endif // EIGHT_PUZZLE_MODEL_BOARD_H_