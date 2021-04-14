#include <sstream>
#include <time.h>
#include <stdlib.h>

#include "board.h"
#include "state.h"
#include "utils.h"

Board::Board(int n)
	: n_(n)
	, board_(nullptr)
	, solution_(nullptr)
{
	board_ = new int * [n_];

	// Temporary solution: Generate a random permutation of an array of size n_ * n_
	// 	containing numbers from 0 to (n_ * n_ - 1) and copy them to the board_.
	// 	   A better solution would be extending a random permutation of an 2d array of
	// 	   dimension n_ x n_. But this should do for now.
	// Masked off with 64 - bits to avoid overflow.
	int* random_array = RandomPermutation(n_ * n_);

	// PrintIntArray(random_array, (size_t) (n_ * n_ & 0xFFFFFFFF));

	for (int i = 0; i < n_; i++) {
		board_[i] = new int[n_];
		for (int j = 0; j < n_; j++) {
			board_[i][j] = random_array[i * n_ + j];
			if (random_array[i * n_ + j] == 0) blank_ = Point(i, j);
		}
	}

	GenerateSolutionBoard();

	delete[] random_array;

}

Board::Board(const Board& b)
	: n_(b.n_)
	, board_(nullptr)
	, solution_(nullptr)
{
	board_ = new int * [n_];

	// Perform a deep copy of the board.
	for (int i = 0; i < n_; i++) {
		board_[i] = new int[n_];
		for (int j = 0; j < n_; j++) {
			board_[i][j] = b.board_[i][j];
			if (board_[i][j] == 0) blank_ = Point(i, j);
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
	board_ = new int * [n_];

	for (int i = 0; i < n_; i++) {
		board_[i] = new int[n_];
		for (int j = 0; j < n_; j++) {
			board_[i][j] = b.board_[i][j];
			if (board_[i][j] == 0) blank_ = Point(i, j);
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

std::vector<Move> Board::GetPossibleMoves()
{
	std::vector<Move> possible_moves;

	int blank_x = blank_.GetX();
	int blank_y = blank_.GetY();

	if (blank_x > 0)
		possible_moves.push_back(Move(blank_x, blank_y, blank_x - 1, blank_y));

	if (blank_x < n_ - 1)
		possible_moves.push_back(Move(blank_x, blank_y,
			blank_x + 1, blank_y));

	if (blank_y > 0)
		possible_moves.push_back(Move(blank_x, blank_y,
			blank_x, blank_y - 1));

	if (blank_y < n_ - 1)
		possible_moves.push_back(Move(blank_x, blank_y,
			blank_x, blank_y + 1));
	
	return possible_moves;
}

std::string Board::CurrentBoardToString()
{
	std::string result("");
	
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			result.append(std::to_string(board_[i][j]));
			result.append("\t");
		}
		result.append("\n");
	}

	result.append("Blank position: (");
	result.append(std::to_string(blank_.GetX()));
	result.append(", ");
	result.append(std::to_string(blank_.GetY()));
	result.append(")\nPossible moves: \n");

	std::vector<Move> possibleMove = GetPossibleMoves();
	for (std::vector<Move>::iterator it = possibleMove.begin();
		it != possibleMove.end(); ++it)
		result.append((*it).ToString().c_str());
	return result;
}

std::string Board::SolutionBoardToString()
{
	std::string result("");

	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			result.append(std::to_string(solution_[i][j]));
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

void Board::PrintBoard(int** b)
{
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			printf("%d ", b[i][j]);
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
	solution_ = new int * [n_];
	for (int i = 0; i < n_; i++) {
		solution_[i] = new int[n_];
		for (int j = 0; j < n_; j++) {
			solution_[i][j] = 0;
		}
	}
	
	while (true) {
		if (left > right) break;

		// Fill out the top row.
		for (int i = left; i <= right; i++) {
			solution_[top][i] = arr[index++];
		}	
		top++;
		
		if (top > bottom) break;

		// Fil out the right column.
		for (int i = top; i <= bottom; i++) {
			solution_[i][right] = arr[index++];
		}
		right--;
		
		if (left > right) break;

		// Fill out the bottom row.
		for (int i = right; i >= left; i--) {
			solution_[bottom][i] = arr[index++];
		}
		bottom--;
		if (top > bottom) break;

		// Fill out the left column.
		for (int i = bottom; i >= top; i--) {
			solution_[i][left] = arr[index++];
		}
		left++;
		
	}

	delete[] arr;
}

bool Board::IsSolved() const
{
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			if (board_[i][j] != solution_[i][j])
				return false;
		}
	}
	return true;
}

void Board::MoveBlank(const Move &m)
{
	int start_x = m.GetStartPoint().GetX();
	int start_y = m.GetStartPoint().GetY();

	int end_x = m.GetEndPoint().GetX();
	int end_y = m.GetEndPoint().GetY();

	board_[start_x][start_y] = board_[end_x][end_y];
	board_[end_x][end_y] = 0;
	blank_.SetX(end_x);
	blank_.SetY(end_y);
}

void Board::ReverseMove(const Move& m)
{
	int start_x = m.GetStartPoint().GetX();
	int start_y = m.GetStartPoint().GetY();

	int end_x = m.GetEndPoint().GetX();
	int end_y = m.GetEndPoint().GetY();

	board_[end_x][end_y] = board_[start_x][start_y];
	board_[start_x][start_y] = 0;
	blank_.SetX(start_x);
	blank_.SetY(start_y);
}
