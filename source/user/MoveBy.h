#ifndef _MOVE_BY_H_
#define _MOVE_BY_H_

#include "user/MoveTo.h"

//description of the class here
class MoveBy: public MoveTo
{
public:
	MoveBy(VisibleObject* host, int duration, Coord vect, bool isRepeat);
	MoveBy* create(VisibleObject* host, int duration, Coord vect, bool isRepeat);
};
#endif
