/*
* iview.h
* 
* Interface for View in MVC model.
*/

#ifndef SLIDING_PUZZLE_VIEWS_IVIEW_H_
#define SLIDING_PUZZLE_VIEWS_IVIEW_H_

class IView
{
public:
	virtual ~IView() {};
	// Forbid copying
	IView(IView const&) = delete;
	IView& operator=(IView const&) = delete;

protected:
	IView() {};

private:
};

#endif // SLIDING_PUZZLE_VIEWS_IVIEW_H_