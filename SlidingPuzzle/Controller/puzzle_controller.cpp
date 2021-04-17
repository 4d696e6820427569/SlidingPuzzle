#include "puzzle_controller.h"
#include "../Model/search_a_star.h"
#include "../Model/isearch.h"


PuzzleController::PuzzleController()
	: state_(nullptr)
	, strategy_(nullptr)
{

}

PuzzleController::PuzzleController(State* b)
	: state_(b)
	, strategy_(nullptr)
{

}

PuzzleController::PuzzleController(State* b, ISearch* s)
	: state_(b)
	, strategy_(s){

}

PuzzleController::~PuzzleController()
{
	if (strategy_ != nullptr) delete strategy_;
	
}


void PuzzleController::SetStrategy(ISearch* strategy)
{
	this->strategy_ = strategy;
}

ISearch* PuzzleController::GetStrategy() const
{
	return this->strategy_;
}

void PuzzleController::Solve()
{
	this->strategy_->Execute(state_);
}

void PuzzleController::MoveBlankCell(const Move&)
{
	
}

void PuzzleController::UndoMoveBlankCell()
{

}