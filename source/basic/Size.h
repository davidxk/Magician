#ifndef _SIZE_H_
#define _SIZE_H_

#include "basic/OrderedPair.h"

//Size is never negative
class Size: public OrderedPair
{
public:
	Size(int aLine = 0, int aColumn = 0);
	void verify();
	bool operator==(const Size& cc);
	bool operator!=(const Size& cc);
};
#endif
