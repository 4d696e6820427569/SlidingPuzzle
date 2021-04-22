#include "text_view.h"
#include "../Tests/board_tests.hpp"

TextView::TextView()
	: puzzle_controller_(nullptr)
	, init_state_(nullptr)
{

}

TextView::TextView(PuzzleController* c, State* is)
	: puzzle_controler_(c)
	, init_state_(is)
{

}

TextView::TextView(PuzzleController* c)
	: puzzle_controler_(c)
	, init_state_(nullptr)
{

}


TextView::~TextView()
{
	//if (puzzle_controller != nullptr) delete puzzle_controller_;
	//if (init_state_ != nullptr) delete puzzle_controller;
}

void TextView::Run()
{

	PrintUsage();


	std::string cmd;
	std::string strategy;

	while (cmd != "quit") {
		printf("Available commands: \n");
		printf("1. Set strategy. The default strategy is A* search.\n");
		printf("2. Run easy test case: 1 3 4 8 6 2 7 0 5\n");
		printf("3. Run medium test case: 2 8 1 0 4 3 7 6 5\n");
		printf("4. Run hard test case: 5 6 7 4 0 8 3 2 1\n");
		printf("5. Run custom test case.\n");
		printf("6. Quit\n");
		
		std::cin >> cmd;

		switch (cmd[0]) {
		case '1':
			printf("Available strategies:\n");
			printf("1. Breadth first search\n");
			printf("2. Depth first search\n");
			printf("3. Uniform cost search\n");
			printf("4. A* Search\n");
			printf("5. Greedy best first search\n");
			
			while (strategy[0] <= '0' || strategy[1] >= '6') {
				std::cin >> strategy;
				switch (strategy[0]) {
				case '1':
					controller_->SetStrategy("BFS");
					break;
				case '2':
					controller_->SetStrategy("DFS");
					break;
				case '3':
					controller_->SetStrategy("UCS");
					break;
				case '4':
					controller_->SetStrategy("AStarS");
					break;
				case '5':
					controller_->SetStrategy("GBFS");
					break;
				default:
					break;
				}
			}
			break;
		case '2':
			Test::EasyTest(puzzle_controller_);
			break;
		case '3':
			Test::MediumWebTest(puzzle_controller_);
			break;
		}
		case '4':
			Test::HardWebTest(puzzle_controller_);
			break;
		case '5':
			PrintUsage();
			std::string custom;
			std::cin >> custom;
			Test::CustomProblem(puzzle_controller_, custom);
			break;
		case '6':
			return;
		default:
			break;
	}
	
}

void TextView::PrintHeader()
{
	printf("#########################################\n");
	printf("#   CSC 480 Artificial Intelligence I   #\n");
	printf("#     Assignment 1 : 8-puzzle solver	#\n");
	printf("#				Minh Bui			    #\n");
	printf("#########################################\n");
}

void TextView::PrintUsage()
{
	printf("Please input an 8-puzzle problem in the format: 1 2 3 8 0 4 7 6 5\n");
	printf("Example:\n");
	printf("1\t2\t3\n");
	printf("8\t0\t4\n");
	printf("7\t6\t5\n");
}
