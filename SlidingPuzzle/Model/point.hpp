/*
* Point class
*  Abstraction of 2D Cartesian coordinates.
*/

#ifndef SLIDING_PUZZLE_MODEL_POINT_HPP_
#define SLIDING_PUZZLE_MODEL_POINT_HPP_

class Point
{
public:
	Point()
		: x_(0)
		, y_(0) {};

	Point(unsigned int x, unsigned int y)
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

	inline void SetX(unsigned int x) { this->x_ = x; }
	inline unsigned int GetX() const { return this->x_; }
	inline void SetY(unsigned int y) { this->y_ = y; }
	inline unsigned int GetY() const { return this->y_; }

private:
	unsigned int x_;
	unsigned int y_;
};

#endif // SLIDING_PUZZLE_MODEL_POINT_HPP_