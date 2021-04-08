/*
* Board
* Models the 2d board in the sliding puzzle. It contains n x n cells.
* 
* 
*/

#ifndef EIGHT_PUZZLE_MODEL_BOARD_H_
#define EIGHT_PUZZLE_MODEL_BOARD_H_

#include <string>

#include "cell.h"

#define DEFAULT_BOARD_SIZE 3

class Board
{
public:
	Board();
	Board(unsigned int);
	Board(const Board& b);
	~Board();
	Board& operator = (const Board& b);

	inline unsigned int Size() const { return n_; }
	unsigned int* GetBlankCoordinates();
	unsigned int* ReAssignBlank();
	std::string ToString();

private:
	Cell** board_;
	unsigned int n_;
	unsigned int* blank_coordinates_;
};

#endif // EIGHT_PUZZLE_MODEL_BOARD_H_