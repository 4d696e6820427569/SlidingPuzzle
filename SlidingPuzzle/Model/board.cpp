#include <sstream>
#include <time.h>
#include <stdlib.h>

#include "board.h"
#include "utils.h"

Board::Board(int n)
	: n_(n)
	, blank_(nullptr)
	, board_(nullptr)
	, solution_(nullptr)
{
	board_ = new Cell* [n_];
	
	// Temporary solution: Generate a random permutation of an array of size n_ * n_
	// 	containing numbers from 0 to (n_ * n_ - 1) and copy them to the board_.
	// 	   A better solution would be extending a random permutation of an 2d array of
	// 	   dimension n_ x n_. But this should do for now.
	// Masked off with 64 - bits to avoid overflow.
	int* random_array = RandomPermutation(n_ * n_);

	// PrintIntArray(random_array, (size_t) (n_ * n_ & 0xFFFFFFFF));

	for (int i = 0; i < n_; i++) {
		board_[i] = new Cell[n_];
		for (int j = 0; j < n_; j++) {
			board_[i][j] = Cell(random_array[i * n_ + j], i, j);
			if (random_array[i * n_ + j] == 0) blank_ = &board_[i][j];
		}
	}
	
	GenerateSolutionBoard();
	delete[] random_array;
}

Board::Board(const Board& b)
	: n_(b.n_)
	, blank_(nullptr)
	, board_(nullptr)
	, solution_(nullptr)
{
	board_ = new Cell * [n_];

	// Perform a deep copy of the board.
	for (int i = 0; i < n_; i++) {
		board_[i] = new Cell[n_];
		for (int j = 0; j < n_; j++) {
			board_[i][j] = b.board_[i][j];
			if (board_[i][j].GetValue() == 0) blank_ = &board_[i][j];
		}
	}
	GenerateSolutionBoard();
}

Board& Board::operator=(const Board& b)
{
	for (int i = 0; i < n_; i++) {
		delete[] board_[i];
		delete[] solution_[i];
	}
	
	delete[] board_;
	delete[] solution_;
	
	n_ = b.n_;
	board_ = new Cell * [n_];

	for (int i = 0; i < n_; i++) {
		board_[i] = new Cell[n_];
		for (int j = 0; j < n_; j++) {
			board_[i][j] = b.board_[i][j];
			if (board_[i][j].GetValue() == 0) blank_ = &board_[i][j];
		}
	}

	GenerateSolutionBoard();
	return *this;
}

Board::~Board()
{
	for (int i = 0; i < n_; i++)
		delete[] board_[i];

	delete[] board_;
	
	for (int i = 0; i < n_; i++)
		delete[] solution_[i];
	
	delete[] solution_;
}

void Board::GetPossibleMoves()
{
	
}

std::string Board::CurrentBoardToString()
{
	std::string result("");
	
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			result.append(board_[i][j].ToString());
			result.append("\t");
		}
		result.append("\n");
	}

	return result;
}

std::string Board::SolutionBoardToString()
{
	std::string result("");

	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			result.append(solution_[i][j].ToString());
			result.append("\t");
		}
		result.append("\n");
	}

	return result;
}

bool Board::operator == (const Board& b)
{
	if (b.Size() != this->Size())
		return false;
	
	for (int i = 0; i < this->Size(); i++) {
		for (int j = 0; j < this->Size(); j++) {
			if (this->board_[i][j] != b.board_[i][j])
				return false;
		}
	}
	return true;
}

void Board::PrintBoard(Cell** b)
{
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			printf("%d ", b[i][j].GetValue());
		}
		printf("\n");
	}
}

void Board::GenerateSolutionBoard()
{
	int totalSize = n_ * n_;
	int top = 0;
	int bottom = n_ - 1;
	int left = 0;
	int right = n_ - 1;
	int index = 0;

	// Initialize
	int* arr = new int[totalSize];
	for (int i = 0; i < totalSize; i++)
		arr[i] = i+1;
	arr[totalSize - 1] = 0;

	// Initialize solution board if it's not already initialized.
	solution_ = new Cell * [n_];
	for (int i = 0; i < n_; i++) {
		solution_[i] = new Cell[n_];
		for (int j = 0; j < n_; j++) {
			solution_[i][j] = Cell(0, i, j);
		}
	}
	
	while (true) {
		if (left > right) break;

		// Fill out the top row.
		for (int i = left; i <= right; i++) {
			solution_[top][i].SetValue(arr[index++]);
		}	
		top++;
		
		if (top > bottom) break;

		// Fil out the right column.
		for (int i = top; i <= bottom; i++) {
			solution_[i][right].SetValue(arr[index++]);
		}
		right--;
		
		if (left > right) break;

		// Fill out the bottom row.
		for (int i = right; i >= left; i--) {
			solution_[bottom][i].SetValue(arr[index++]);
		}
		bottom--;
		if (top > bottom) break;

		// Fill out the left column.
		for (int i = bottom; i >= top; i--) {
			solution_[i][left].SetValue(arr[index++]);
		}
		left++;
		
	}

	delete[] arr;
}