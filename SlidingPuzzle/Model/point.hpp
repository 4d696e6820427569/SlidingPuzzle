/*
* Point class
*  Abstraction of 2D Cartesian coordinates.
*/

#ifndef SLIDING_PUZZLE_MODEL_POINT_HPP_
#define SLIDING_PUZZLE_MODEL_POINT_HPP_

#include <cmath>

struct Point
{

	Point()
		: x_(0)
		, y_(0) {};

	Point(int x, int y)
		: x_(x)
		, y_(y) {};

	Point(const Point& p)
		: x_(p.x_)
		, y_(p.y_) {};

	Point& operator=(const Point& p) 
	{ 
		this->x_ = p.x_; 
		this->y_ = p.y_; 
		return *this; 
	}

	~Point() {}

	inline int GetManhattanDistance(const Point& p)
	{
		return abs(x_ - p.x_) + abs(y_ - p.y_);
	}

	int x_;
	int y_;
};

#endif // SLIDING_PUZZLE_MODEL_POINT_HPP_