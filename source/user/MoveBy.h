#ifndef _MOVE_BY_H_
#define _MOVE_BY_H_

#include "user/MoveTo.h"

//description of the class here
class MoveBy: public Action
{
public:
	MoveBy(VisibleObject* host, int duration, Coord aVect, bool isRepeat);
	virtual MoveBy* clone() const override;
	static MoveBy* create(VisibleObject* host, int duration, Coord aVect, bool isRepeat=false);
	static MoveBy* create(int duration, Coord aVect, bool isRepeat=false);
	virtual void getCmdQueue() override;
private:
	Coord vect;
};
#endif
