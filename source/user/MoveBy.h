#ifndef _MOVE_BY_H_
#define _MOVE_BY_H_

#include "base/Command.h"
#include "user/MoveTo.h"

//MoveBy action moves a sprite by a specified vector
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



//MoveByCommand modifies a sprites position by a certain vector
class MoveByCommand: public Command
{
public:
	MoveByCommand(Coord aBy);
	virtual void apply(VisibleObject* vo);
private:
	Coord by;
};
#endif
