/*
* Move class
*	Abstraction that captures how a cell in the puzzle can move.
*/

#ifndef SLIDING_PUZZLE_MODEL_MOVE_H_
#define SLIDING_PUZZLE_MODEL_MOVE_H_

#endif // SLIDING_PUZZLE_MODEL_MOVE_H_

enum Moves
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Move
{
public:
private:
	Cell* cell_;
	Moves move_;
};