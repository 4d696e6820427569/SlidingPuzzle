/*
* Move class
*	Abstraction that captures how a cell in the puzzle can move.
*/

#ifndef SLIDING_PUZZLE_MODEL_MOVE_HPP_
#define SLIDING_PUZZLE_MODEL_MOVE_HPP_

#include <string>

#include "point.hpp"

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Move
{
public:
	Move() = delete;
	Move(int x1, int y1, int x2, int y2, unsigned long cost)
		: start_(Point(x1, y1))
		, end_(Point(x2, y2))
		, cost_(cost) {}
	
	Move(const Move& m)
		: start_(m.start_)
		, end_(m.end_)
		, cost_(m.cost_){}

	Move& operator=(const Move& m)
	{
		start_ = m.start_;
		end_ = m.end_;
		cost_ = m.cost_;
	}

	~Move() = default;

	Point GetStartPoint() const { return this->start_; }
	Point GetEndPoint() const { return this->end_;  }
	unsigned long GetCost() const { return this->cost_; }
	void SetCost(unsigned long c) { this->cost_ = c; }

	std::string ToString()
	{
		// This is so bad. Temporary solution.
		std::string result("");
		result.append("(");
		result.append(std::to_string(start_.GetX()));
		result.append(", ");
		result.append(std::to_string(start_.GetY()));
		result.append(") to ");
		
		result.append("(");
		result.append(std::to_string(end_.GetX()));
		result.append(", ");
		result.append(std::to_string(end_.GetY()));
		result.append(")\n");

		return result;
	}

private:
	Point start_;
	Point end_;
	unsigned long cost_;
};

#endif // SLIDING_PUZZLE_MODEL_MOVE_HPP_