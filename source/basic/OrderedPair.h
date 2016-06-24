#ifndef _ORDERED_PAIR_
#define _ORDERED_PAIR_

#include "basic/Object.h"

//Base to all Size and Coords
class OrderedPair: public Object
{
public:
	int line;
	int column;
	OrderedPair() { };
	OrderedPair(int aLine, int aColumn);
};
#endif
