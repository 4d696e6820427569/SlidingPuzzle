/*
* Board
* Models the 2d board in the sliding puzzle. It contains n x n cells.
*/

#ifndef EIGHT_PUZZLE_MODEL_BOARD_H_
#define EIGHT_PUZZLE_MODEL_BOARD_H_

#include <string>
#include <vector>

#include "move.hpp"

class Board
{
public:
	Board(int n = 3);
	Board(const Board& b);
	~Board();
	Board& operator = (const Board& b);

	bool operator == (const Board& b);
	bool IsSolved() const;
	int Size() const { return n_; }
	Point GetBlankCoordinates() const { return blank_; }
	void MoveBlank(const Move&);
	void ReverseMove(const Move&);
	std::vector<Move> GetPossibleMoves();
	std::vector<int**>* GetPossibleStates();
	std::string CurrentBoardToString();
	std::string SolutionBoardToString();

private:
	int** board_;
	int** solution_;
	Point blank_;
	int n_;

	void GenerateSolutionBoard();
	void PrintBoard(int** b);
};

#endif // EIGHT_PUZZLE_MODEL_BOARD_H_