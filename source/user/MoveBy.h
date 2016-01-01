#ifndef _MOVE_BY_H_
#define _MOVE_BY_H_

#include "user/MoveTo.h"

//description of the class here
class MoveBy: public MoveTo
{
public:
	MoveBy(VisibleObject* host, int duration, Coord aFrom, Coord aDest, bool isRepeat);
	virtual MoveBy* clone() const override;
	static MoveBy* create(VisibleObject* host, int duration, Coord vect, bool isRepeat=false);
	static MoveBy* create(int duration, Coord vect, bool isRepeat=false);
	virtual void initWithHost(VisibleObject* host) override;
};
#endif
