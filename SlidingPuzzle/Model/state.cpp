#include "state.h"

State::State()
	: n_(0)
	, board_(nullptr)
{

}

State::State(const Board& b, const Move& m)
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

	this->MoveBlank(m);
	this->moves_.push_back(m);
}

State::State(State& s, const Move& m)
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

	// Copy the previous moves onto this state's move to keep track of the path.
	for (std::vector<Move>::iterator it = s.moves_.begin();
		it != s.moves_.end(); ++it)
		this->moves_.push_back(*it);

	this->MoveBlank(m);
	this->moves_.push_back(m);
}

State& State::operator=(State& s)
{
	for (int i = 0; i < n_; i++)
		delete board_[i];
	delete[] board_;

	this->n_ = s.n_;
	board_ = new int* [n_];
	for (int i = 0; i < n_; i++) {
		board_[i] = new int[n_];
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

	return *this;
}

State::State(const Board& b)
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
}

State::~State()
{
	for (int i = 0; i < this->n_; i++) {
		delete [] board_[i];
	}
	delete[] board_;
}

std::vector<State*>* State::GetPossibleStatesFromBoard(Board& b)
{
	std::vector<State*>* possible_states = new std::vector<State*>();

	std::vector<Move> possible_moves = b.GetPossibleMoves();

	// Need to also include the current state.

	for (std::vector<Move>::iterator it = possible_moves.begin();
		it != possible_moves.end(); ++it) {
		Move cur_move = *it;
		possible_states->push_back(new State(b, cur_move));
	}

	return possible_states;
}

std::vector<State*>* State::GetPossibleStates()
{
	std::vector<State*>* possible_moves = new std::vector<State*>();

	int blank_x = blank_.GetX();
	int blank_y = blank_.GetY();

	if (blank_x > 0)
		possible_moves->push_back(new State(*this, Move(blank_x, blank_y, blank_x - 1, blank_y)));

	if (blank_x < n_ - 1)
		possible_moves->push_back(new State(*this, Move(blank_x, blank_y,
			blank_x + 1, blank_y)));

	if (blank_y > 0)
		possible_moves->push_back(new State(*this, Move(blank_x, blank_y,
			blank_x, blank_y - 1)));

	if (blank_y < n_ - 1)
		possible_moves->push_back(new State(*this, Move(blank_x, blank_y,
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

bool State::IsGoalState(Board& b)
{
	int** solution = b.GetSolutionBoard();
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			if (board_[i][j] != solution[i][j])
				return false;
		}
	}
	return true;
}

bool State::operator==(const State& s)
{
	if (this->n_ != s.n_) return false;
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < n_; j++) {
			if (board_[i][j] != s.board_[i][j])
				return false;
		}
	}
	return true;
}

void State::MoveBlank(const Move& m)
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

void State::ReverseMove(const Move& m)
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