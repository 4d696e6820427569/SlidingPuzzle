// eight_puzzle_main.cpp : Defines the entry point for the application.
//

#define _CRTDBG_MAP_ALLOC
#define DEBUG 1
#include <stdlib.h>
#include <crtdbg.h>


#include "./Tests/puzzle_tests.hpp"

int main()
{
	Test::RunAllTests();
	if (DEBUG) _CrtDumpMemoryLeaks();
	return 0;
}
