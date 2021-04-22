#include "puzzle_controller.h"
#include "../Model/search_a_star.h"
#include "../Model/search_greedy_best_first.h"
#include "../Model/search_depth_first.h"
#include "../Model/search_breadth_first.h"
#include "../Model/search_uniform_cost.h"
#include "../Model/isearch.h"

PuzzleController::PuzzleController()
	: state_(nullptr)
	, strategy_(nullptr)
{
	strategies_["BFS"] = new Bfs();
	strategies_["DFS"] = new Dfs();
	strategies_["UCS"] = new Ucs();
	strategies_["AStarS"] = new AStarSearch();
	strategies_["GBFS"] = new GreedyBestFirst();
	strategy_ = strategies_["AStarS"];
}

PuzzleController::PuzzleController(State* b)
	: state_(b)
	, strategy_(nullptr)
{
	strategies_["BFS"] = new Bfs();
	strategies_["DFS"] = new Dfs();
	strategies_["UCS"] = new Ucs();
	strategies_["AStarS"] = new AStarSearch();
	strategies_["GBFS"] = new GreedyBestFirst();
	strategy_ = strategies_["AStarS"];
}

PuzzleController::~PuzzleController()
{
	for (auto strategy : strategies_) {
		delete strategies_[strategy.first];
	}
}


void PuzzleController::SetState(State* s)
{
	if (state_ != nullptr) delete state_;
	state_ = s;
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

void PuzzleController::SetStrategy(std::string strategy)
{
	if (this->strategies_.find(strategy) != this->strategies_.end()) {
		this->strategy_ = this->strategies_[strategy];
	}
}

std::string PuzzleController::AvailableStrategies()
{
	std::string result("Available strategies:\n");
	for (auto strategy : strategies_) {
		result += "\t" + strategy.first + "\n";
	}
	return result;
}