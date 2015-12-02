#ifndef _SIZE_H_
#define _SIZE_H_

#include "basic/OrderedPair.h"

class Size: public OrderedPair
{
public:
	Size(int aLine = 0, int aColumn = 0);
	void verify();
};
#endif
