#include "puzzle_controller.h"
#include "../Model/search_a_star.h"
#include "../Model/isearch.h"


PuzzleController::PuzzleController()
	: board_(nullptr)
	, strategy_(nullptr)
	, moves_stack_(new std::stack<Move>())
{

}

PuzzleController::PuzzleController(Board* b)
	: board_(b)
	, strategy_(nullptr)
	, moves_stack_(new std::stack<Move>())
{

}

PuzzleController::PuzzleController(Board* b, ISearch* s)
	: board_(b)
	, strategy_(s)
	, moves_stack_(new std::stack<Move>())
{

}

PuzzleController::~PuzzleController()
{
	delete moves_stack_;
}

void PuzzleController::GenerateNewBoard(int n)
{
	if (board_ != nullptr) {
		delete board_;
	}

	board_ = new Board(n);
}

void PuzzleController::SetStrategy(ISearch* strategy)
{
	this->strategy_ = strategy;
}

ISearch* PuzzleController::GetStrategy() const
{
	return this->strategy_;
}

void PuzzleController::MoveBlankCell(const Move& move)
{
	moves_stack_->push(move);
	board_->MoveBlank(move);
}

void PuzzleController::UndoMoveBlankCell()
{
	if (!moves_stack_->empty()) { 
		board_->ReverseMove(moves_stack_->top());
		moves_stack_->pop();
	}
}

void PuzzleController::Solve()
{
	this->strategy_->Execute(board_);
}