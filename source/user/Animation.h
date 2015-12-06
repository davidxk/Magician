#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "base/Action.h"
#include "base/VisibleObject.h"
#include "basic/Coord.h"

//description of the class here
class Animation: public Action
{
public:
	Animation(VisibleObject* host, int duration, bool isRepeat=false);
	static Animation* create(VisibleObject* host, int duration, bool isRepeat=false);
	virtual void getCmdQueue() override;
private:
	int frames;
};
#endif
