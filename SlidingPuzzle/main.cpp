// eight_puzzle_main.cpp : Defines the entry point for the application.
//


#define DEBUG 1
#ifdef _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif
#include <stdlib.h>


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
#ifdef _WIN32
	if (DEBUG) _CrtDumpMemoryLeaks();
#endif
	return 0;
}
