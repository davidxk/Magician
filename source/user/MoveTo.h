#ifndef _MOVE_TO_H_
#define _MOVE_TO_H_

#include "base/Action.h"
#include "base/Command.h"
#include "base/VisibleObject.h"
#include "basic/Coord.h"

//Move To action moves an object to the specified coordinate within duration
class MoveTo: public Action
{
public:
	//It figures out Coord from from host pointer
	MoveTo(VisibleObject* host, int duration, Coord aFrom, Coord aDest, bool isRepeat=false);
	static MoveTo* create(int duration, Coord aFrom, Coord aDest, bool isRepeat=false);
	static MoveTo* create(VisibleObject* host, int duration, Coord aDest, bool isRepeat=false);
	virtual MoveTo* clone() const override;
	virtual void initWithHost(VisibleObject* host) override;
	virtual void getCmdQueue() override;
protected:
	Coord from;
	Coord dest;
};



//MoveToCommand modifies a sprites position to a certain position
class MoveToCommand: public Command
{
public:
	MoveToCommand(Coord aPos);
	virtual void apply(VisibleObject* vo);
private:
	Coord pos;
};
#endif
