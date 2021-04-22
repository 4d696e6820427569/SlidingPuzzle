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
	virtual ~IView() = 0;
	virtual void Run() = 0;
private:
};

#endif // SLIDING_PUZZLE_VIEWS_IVIEW_H_