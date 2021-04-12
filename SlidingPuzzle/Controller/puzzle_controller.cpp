#include "puzzle_controller.h"
#include "../Model/search_a_star.h"


PuzzleController::PuzzleController()
	: board_(nullptr)
	, strategy_(nullptr)
{

}

PuzzleController::PuzzleController(Board* b)
	: board_(b)
	, strategy_(nullptr)
{

}

PuzzleController::PuzzleController(Board* b, ISearch* s)
	: board_(b)
	, strategy_(s)
{

}

void PuzzleController::GenerateNewBoard(int n)
{
	if (board_ != nullptr) {
		delete board_;
	}

	board_ = new Board(n);
}

void PuzzleController::SetStrategy(ISearch& strategy)
{
	this->strategy_ = &strategy;
}

ISearch* PuzzleController::GetStrategy() const
{
	return this->strategy_;
}

void PuzzleController::MoveBlankCell(const Move& move)
{
	board_->MoveBlank(move);
}