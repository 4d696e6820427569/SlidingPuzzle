/*
* text_view.h
* Text view for sliding puzzle.
*/

#ifndef SLIDING_PUZZLE_VIEWS_TEXT_VIEW_H_
#define SLIDING_PUZZLE_VIEWS_TEXT_VIEW_H_

#include "../Controller/puzzle_controller.h"
#include "../Model/state.h"
#include "iview.h"

class TextView : public IView
{
public:
	TextView();
	TextView(PuzzleController*);
	TextView(PuzzleController*, State*);
	~TextView();

	void Run();

private:
	PuzzleController *puzzle_controller_;

	void PrintUsage();
	void PrintHeader();
};

#endif // SLIDING_PUZZLE_VIEWS_TEXT_VIEW_H_
