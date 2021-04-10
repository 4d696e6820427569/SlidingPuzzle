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
	Board(unsigned int n = 3);
	Board(const Board& b);
	~Board();
	Board& operator = (const Board& b);

	inline unsigned int Size() const { return n_; }
	inline Cell* GetBlankCell() const { return blank_; }
	void GetPossibleMoves();
	std::string ToString();

private:
	Cell** board_;
	unsigned int n_;
	Cell* blank_;
};

#endif // EIGHT_PUZZLE_MODEL_BOARD_H_