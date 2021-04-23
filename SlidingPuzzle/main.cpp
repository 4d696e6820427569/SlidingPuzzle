// eight_puzzle_main.cpp : Defines the entry point for the application.
//

#define _CRTDBG_MAP_ALLOC
#define DEBUG 1
#include <stdlib.h>
#include <crtdbg.h>

#include "Views/iview.h"
#include "Views/text_view.h"


int main()
{
	{
		PuzzleController mainController;
		TextView textView(&mainController);
		textView.Run();
		//if (DEBUG) Test::RunAllTests(mainController);
		//printf("%llu\n", sizeof(Board));
	}
	if (DEBUG) _CrtDumpMemoryLeaks();
	return 0;
}
