/*
* Cell
*
* Represents a single cell in the sliding puzzle.
*/

#ifndef EIGHT_PUZZLE_MODEL_CELL_H_
#define EIGHT_PUZZLE_MODEL_CELL_H_

#include "Point.hpp"

class Cell
{
public:
	Cell()
		: value_(0)
		, coordinates_(new Point())
	{}

	Cell(int v)
		: value_(v)
		, coordinates_(new Point())
	{}

	Cell(int v, int x, int y)
		: value_(v)
		, coordinates_(new Point(x, y))
	{}

	Cell(Cell& c)
		: value_(c.GetValue())
		, coordinates_(new Point(c.GetX(), c.GetY()))
	{}

	~Cell()
	{
		delete coordinates_;
	}

	Cell& operator=(const Cell& c)
	{
		this->value_ = c.value_;
		if (coordinates_ == nullptr) {
			coordinates_ = new Point(c.GetX(), c.GetY());
		}
		else {
			this->SetX(c.GetX());
			this->SetY(c.GetY());
		}
		return *this;
	}

	inline int GetValue() { return value_; }
	inline void SetValue(int v) { value_ = v; }
	inline void SetX(int x) const { coordinates_->SetX(x); }
	inline unsigned int GetX() const { return coordinates_->GetX(); }
	inline void SetY(int y) const { coordinates_->SetY(y); }
	inline unsigned int GetY() const { return coordinates_->GetY(); }
	inline std::string ToString() { return std::to_string(value_); }

	bool operator != (const Cell& c) { 
		return value_ != c.value_ || GetX() != c.GetX() || GetY() != c.GetY();
	}

private:
	int value_;
	Point* coordinates_;
};

#endif // EIGHT_PUZZLE_MODEL_CELL_H_