/*
* Board
* Models the 2d board in the sliding puzzle. It contains n x n cells.
*/

#ifndef SLIDING_PUZZLE_MODEL_BOARD_H_
#define SLIDING_PUZZLE_MODEL_BOARD_H_

#include <string>
#include <vector>

#include "move.hpp"

class Board
{
public:
	Board(int n = 3, bool solved = false);
	Board(const Board& b);
	Board(int** matrix, int n);
	~Board();
	Board& operator = (const Board& b);

	bool operator == (const Board& b);
	bool IsSolved() const;
	int Size() const { return n_; }

	int** GetBoard() const { return board_; }
	int** GetSolutionBoard() const { return solution_; }
	Point GetBlankCoordinates() const { return blank_; }

	void MoveBlank(const Move&);
	void ReverseMove(const Move&);

	std::vector<Move> GetPossibleMoves();

	std::string CurrentBoardToString();
	std::string SolutionBoardToString();

private:
	int** board_;
	int** solution_;
	int n_;
	Point blank_;
	void GenerateSolutionBoard();
	void PrintBoard(int** b);
};

#endif // EIGHT_PUZZLE_MODEL_BOARD_H_