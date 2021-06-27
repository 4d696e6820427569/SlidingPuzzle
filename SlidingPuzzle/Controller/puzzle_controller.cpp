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
	strategies_["BFS"]		= make_shared<Bfs>();
	strategies_["DFS"]		= make_shared<Dfs>();
	strategies_["UCS"]		= make_shared<Ucs>();
	strategies_["AStar1"]	= make_shared<AStarSearch>(AStarSearch(false));
	strategies_["AStar2"]	= make_shared<AStarSearch>(AStarSearch(true));
	strategies_["GBFS"]		= make_shared<GreedyBestFirst>();
	strategy_				= strategies_["AStar2"];
	cur_strategy_			= "AStar2";
}

PuzzleController::PuzzleController(State* b)
	: strategy_(nullptr)
{
	state_.reset(b);
	strategies_["BFS"]		= make_shared<Bfs>();
	strategies_["DFS"]		= make_shared<Dfs>();
	strategies_["UCS"]		= make_shared<Ucs>();
	strategies_["AStar1"]	= make_shared<AStarSearch>(AStarSearch(false));
	strategies_["AStar2"]	= make_shared<AStarSearch>(AStarSearch(true));
	strategies_["GBFS"]		= make_shared<GreedyBestFirst>();
	strategy_				= strategies_["AStar2"];
	cur_strategy_			= "AStar2";
}

PuzzleController::~PuzzleController()
{
}

void PuzzleController::SetState(State* s)
{
	state_.reset(s);
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
		cur_strategy_ = strategy;
	}
}



std::string PuzzleController::AvailableStrategies()
{
	std::string result("Available strategies:\n");
	for (const auto& strategy : strategies_) {
		result += "\t" + strategy.first + "\n";
	}
	return result;
}