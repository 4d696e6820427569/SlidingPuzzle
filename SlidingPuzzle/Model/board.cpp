#include <sstream>
#include "board.h"
#include <random>

Board::Board()
	: n_(DEFAULT_BOARD_SIZE)
	, blank_coordinates_(nullptr)
{
	board_ = new Cell* [n_];
	for (unsigned int i = 0; i < n_; i++) {
		board_[i] = new Cell[n_];
		for (unsigned int j = 0; j < n_; j++) {
			board_[i][j] = Cell();
		}
	}

	this->GetBlankCoordinates();
}

Board::Board(unsigned int n)
	: n_(n)
	, blank_coordinates_(nullptr)
{
	board_ = new Cell* [n_];
	

	for (unsigned int i = 0; i < n_; i++) {
		board_[i] = new Cell[n_];
		for (unsigned int j = 0; j < n_; j++) {
			board_[i][j] = Cell();
		}
	}
	this->GetBlankCoordinates();
}

Board::Board(const Board& b)
	: n_(b.n_)
	, blank_coordinates_(nullptr)
{
	board_ = new Cell * [n_];

	// Perform a deep copy of the board.
	for (unsigned int i = 0; i < n_; i++) {
		board_[i] = new Cell[n_];
		for (unsigned int j = 0; j < n_; j++) {
			board_[i][j] = b.board_[i][j];
		}
	}

	// Also copy the coordinates of the blank and assign blank
	// to this board using its coordinate.
	blank_coordinates_ = new unsigned int[2];
	blank_coordinates_[0] = b.blank_coordinates_[0];
	blank_coordinates_[1] = b.blank_coordinates_[1];
	board_[blank_coordinates_[0]] = b.board_[blank_coordinates_[0]];
	board_[blank_coordinates_[1]] = b.board_[blank_coordinates_[1]];
}

Board& Board::operator=(const Board& b)
{
	for (unsigned int i = 0; i < n_; i++)
		delete[] board_[i];
	delete[] blank_coordinates_;
	delete[] board_;

	n_ = b.n_;
	board_ = new Cell * [n_];

	for (unsigned int i = 0; i < n_; i++) {
		board_[i] = new Cell[n_];
		for (unsigned int j = 0; j < n_; j++) {
			board_[i][j] = b.board_[i][j];
		}
	}
	
	blank_coordinates_ = new unsigned int[2];
	blank_coordinates_[0] = b.blank_coordinates_[0];
	blank_coordinates_[1] = b.blank_coordinates_[1];

	return *this;
}

Board::~Board()
{
	for (unsigned int i = 0; i < n_; i++)
		delete[] board_[i];

	delete[] board_;
	delete[] blank_coordinates_;
}

unsigned int* Board::GetBlankCoordinates()
{
	if (this->blank_coordinates_ == nullptr) {
		this->blank_coordinates_ = new unsigned int[2];
		this->blank_coordinates_[0] = (unsigned int) rand() % n_;
		this->blank_coordinates_[1] = (unsigned int) rand() % n_;
		board_[blank_coordinates_[0]][blank_coordinates_[1]].SetValue(0);
	}
	return this->blank_coordinates_;
}

unsigned int* Board::ReAssignBlank()
{
	if (this->blank_coordinates_ == nullptr)
		this->blank_coordinates_ = new unsigned int[2];

	this->blank_coordinates_[0] = (unsigned int) rand() % n_;
	this->blank_coordinates_[1] = (unsigned int) rand() % n_;
	board_[blank_coordinates_[0]][blank_coordinates_[1]].SetValue(0);
	return this->blank_coordinates_;
}

std::string Board::ToString()
{
	std::string result("");
	
	for (unsigned int i = 0; i < n_; i++) {
		for (unsigned int j = 0; j < n_; j++) {
			result.append(board_[i][j].ToString());
			result.append("\t");
		}
		result.append("\n");
	}

	return result;
}