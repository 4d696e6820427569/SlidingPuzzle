#include "state.h"

State::State(const Board& b, const Move& m)
	:visited_(false)
{
	this->n_ = b.Size();
	this->board_ = new int* [this->n_];
	for (int i = 0; i < n_; i++) {
		this->board_[i] = new int[n_];
		for (int j = 0; j < n_; j++) {
			this->board_[i][j] = b.GetBoard()[i][j];
			if (this->board_[i][j] == 0) blank_ = Point(i, j);
		}
	}

	this->moves_.push_back(m);
}

State::State(const State& s, const Move& m)
	: visited_(false)
{
	this->n_ = s.n_;
	this->board_ = new int* [this->n_];
	for (int i = 0; i < n_; i++) {
		this->board_[i] = new int[n_];
		for (int j = 0; j < n_; j++) {
			this->board_[i][j] = s.board_[i][j];
			if (this->board_[i][j] == 0) blank_ = Point(i, j);
		}
	}
	this->moves_.push_back(m);
}

State& State::operator=(State& s)
{
	for (int i = 0; i < n_; i++)
		delete board_[i];
	delete[] board_;

	this->n_ = s.n_;
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) { 
			board_[i][j] = s.board_[i][j];
			if (this->board_[i][j] == 0) blank_ = Point(i, j);
		}
	}

	moves_.clear();
	
	for (std::vector<Move>::iterator it = s.moves_.begin();
		it != s.moves_.end(); ++it) {
		moves_.push_back(*it);
	}

	this->visited_ = s.visited_;

	return *this;
}

State::~State()
{
	for (int i = 0; i < this->n_; i++) {
		delete [] board_[i];
	}
	delete[] board_;
}

std::vector<State*> State::GetPossibleStatesFromBoard(Board& b)
{
	std::vector<State*> possible_states;

	std::vector<Move> possible_moves = b.GetPossibleMoves();

	for (std::vector<Move>::iterator it = possible_moves.begin();
		it != possible_moves.end(); ++it) {
		Move cur_move = *it;
		b.MoveBlank(cur_move);
		possible_states.push_back(new State(b, cur_move));
		b.ReverseMove(cur_move);
	}

	return possible_states;
}

std::vector<State> State::GetPossibleStates()
{
	std::vector<State> possible_moves;

	int blank_x = blank_.GetX();
	int blank_y = blank_.GetY();

	if (blank_x > 0)
		possible_moves.push_back(State(*this, Move(blank_x, blank_y, blank_x - 1, blank_y)));

	if (blank_x < n_ - 1)
		possible_moves.push_back(State(*this, Move(blank_x, blank_y,
			blank_x + 1, blank_y)));

	if (blank_y > 0)
		possible_moves.push_back(State(*this, Move(blank_x, blank_y,
			blank_x, blank_y - 1)));

	if (blank_y < n_ - 1)
		possible_moves.push_back(State(*this, Move(blank_x, blank_y,
			blank_x, blank_y + 1)));

	return possible_moves;
}


std::string State::ToString()
{
	std::string result("");

	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			result.append(std::to_string(board_[i][j]));
			result.append("\t");
		}
		result.append("\n");
	}
	return result;
}
