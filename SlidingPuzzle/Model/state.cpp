#include "state.h"

State::State(const Board& b, const Move& m)
	: moves_(nullptr)
	, visited_(false)
{
	this->n_ = b.Size();
	this->board_ = new int* [this->n_];
	for (int i = 0; i < n_; i++) {
		this->board_[i] = new int[n_];
		for (int j = 0; j < n_; j++)
			this->board_[i][j] = b.GetBoard()[i][j];
	}

	this->moves_ = new std::vector<Move>();
	this->moves_->push_back(m);
}

State::State(const State& s, const Move& m)
	: visited_(false)
{
	this->n_ = s.n_;
	this->board_ = new int* [this->n_];
	for (int i = 0; i < n_; i++) {
		this->board_[i] = new int[n_];
		for (int j = 0; j < n_; j++)
			this->board_[i][j] = s.board_[i][j];
	}
	this->moves_->push_back(m);
}

State& State::operator=(const State& s)
{
	for (int i = 0; i < n_; i++)
		delete board_[i];
	delete[] board_;
	delete moves_;

	this->n_ = s.n_;
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			board_[i][j] = s.board_[i][j];
		}
	}

	moves_ = new std::vector<Move>();
	for (std::vector<Move>::iterator it = s.moves_->begin();
		it != s.moves_->end(); ++it) {
		moves_->push_back(*it);
	}

	this->visited_ = s.visited_;

	return *this;
}

State::~State()
{
	if (moves_ != nullptr)
		delete moves_;

	if (board_ != nullptr) {
		for (int i = 0; i < n_; i++) {
			delete board_[i];
		}

		delete[] board_;
	}
}

std::vector<State>* State::GetPossibleStatesFromBoard(Board& b)
{
	std::vector<State>* possible_states = new std::vector<State>();

	std::vector<Move> possible_moves = b.GetPossibleMoves();

	for (std::vector<Move>::iterator it = possible_moves.begin();
		it != possible_moves.end(); ++it) {
		Move cur_move = *it;
		b.MoveBlank(cur_move);
		possible_states->push_back(State(b, cur_move));
		b.ReverseMove(cur_move);
	}

	return possible_states;
}
