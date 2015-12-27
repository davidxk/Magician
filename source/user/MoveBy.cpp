#include "user/MoveBy.h"

MoveBy::MoveBy(VisibleObject* host, int duration, Coord vect, bool isRepeat):
	MoveTo(host, duration, host->pos+vect, isRepeat) { }

MoveBy* MoveBy::create(VisibleObject* host, int duration, Coord vect, bool isRepeat)
{
	return new MoveBy(host, duration, vect, isRepeat);
}
