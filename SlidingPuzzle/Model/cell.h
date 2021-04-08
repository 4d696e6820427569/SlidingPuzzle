/*
* Cell
*
* Represents a single cell in the sliding puzzle.
*/

#ifndef EIGHT_PUZZLE_MODEL_CELL_H_
#define EIGHT_PUZZLE_MODEL_CELL_H_

class Cell
{
public:
	Cell()
		: value_(0)
	{}

	Cell(unsigned int v)
		: value_(v)
	{}

	Cell(Cell& c)
		: value_(c.GetValue())
	{}

	~Cell()
	{

	}

	Cell& operator=(const Cell& c)
	{
		this->value_ = c.value_;
		return *this;
	}

	inline unsigned int GetValue() { return value_; }
	inline void SetValue(unsigned int v) { value_ = v; }
	inline void SetX(unsigned int x) { x_ = x; }
	inline unsigned int GetX() { return x_; }
	inline void SetY(unsigned int y) { y_ = y; }
	inline unsigned int GetY() { return y_; }
	inline std::string ToString() { return std::to_string(value_); }

private:
	unsigned int value_;
	unsigned int x_;
	unsigned int y_;
};

#endif // EIGHT_PUZZLE_MODEL_CELL_H_