#ifndef _ORDERED_PAIR_
#define _ORDERED_PAIR_

//Base to all Size and Coords
class OrderedPair
{
public:
	int line;
	int column;
	OrderedPair() { };
	OrderedPair(int aLine, int aColumn);
};
#endif
