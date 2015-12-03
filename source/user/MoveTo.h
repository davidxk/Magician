#ifndef _MOVE_TO_H_
#define _MOVE_TO_H_

#include "base/Action.h"
#include "base/VisibleObject.h"
#include "basic/Coord.h"

class MoveTo: public Action
{
public:
	//It figures out Coord from from host pointer
	MoveTo(VisibleObject* host, int duration, Coord aDest, bool isRepeat=false);
	static MoveTo* create(VisibleObject* host, int duration, Coord aDest, bool isRepeat=false);
	virtual void getCmdQueue() override;
private:
	Coord from;
	Coord dest;
};
#endif
