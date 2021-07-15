#ifndef SEARCH_INFORMED_H_
#define SEARCH_INFORMED_H_

#include "./isearch.h"

class InformedSearch : public ISearch
{
public:
	virtual void setHeuristicFunction();
	virtual ~InformedSearch() {}
protected:

};

#endif