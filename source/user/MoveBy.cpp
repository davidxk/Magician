#include "user/MoveBy.h"
#include <cassert>

MoveBy::MoveBy(VisibleObject* host, int duration, Coord aFrome, Coord aDest, bool isRepeat):
	MoveTo(host, duration, aFrome, aDest, isRepeat) { }

MoveBy* MoveBy::clone() const
{
	return new MoveBy(*this);
}

MoveBy* MoveBy::create(VisibleObject* host, int duration, Coord vect, bool isRepeat)
{
	assert( host );
	return new MoveBy(host, duration, host->pos, host->pos+vect, isRepeat);
}

MoveBy* MoveBy::create(int duration, Coord vect, bool isRepeat)
{
	return new MoveBy(NULL, duration, Coord(0, 0), vect, isRepeat);
}

void MoveBy::initWithHost(VisibleObject* host)
{
	assert( host );
	this->from = host->pos;
	this->dest = this->from + this->dest;
	while( !cmdQueue.empty() ) cmdQueue.pop();
	getCmdQueue();
}
