#include "user/MoveBy.h"

MoveBy::MoveBy(VisibleObject* host, int duration, Coord vect, bool isRepeat):
	MoveTo(host, duration, host->pos+vect, isRepeat)
{
	this->from = host->pos;
	getCmdQueue();
}

MoveBy* MoveBy::create(VisibleObject* host, int duration, Coord vect, bool isRepeat)
{
	return new MoveBy(host, duration, vect, isRepeat);
}
