/*
* Point class
*  Abstraction of 2D Cartesian coordinates.
*/

#ifndef SLIDING_PUZZLE_MODEL_POINT_HPP_
#define SLIDING_PUZZLE_MODEL_POINT_HPP_

#include <cmath>

class Point
{
public:
	Point()
		: x_(0)
		, y_(0) {};

	Point(int x, int y)
		: x_(x)
		, y_(y) {};

	Point(const Point& p)
		: x_(p.x_)
		, y_(p.y_) {};

	inline Point& operator=(const Point& p) 
	{ 
		this->x_ = p.x_; 
		this->y_ = p.y_; 
		return *this; 
	}

	~Point() {}

	inline void SetX(int x) { this->x_ = x; }
	inline int GetX() const { return this->x_; }
	inline void SetY(int y) { this->y_ = y; }
	inline int GetY() const { return this->y_; }
	inline int GetManhattanDistance(const Point& p)
	{
		return abs(x_ - p.x_) + abs(y_ - p.y_);
	}

private:
	int x_;
	int y_;
};

#endif // SLIDING_PUZZLE_MODEL_POINT_HPP_