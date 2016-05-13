#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "action/Action.h"
#include "action/Command.h"
#include "display/VisibleObject.h"
#include "basic/Coord.h"

//An Animation action asks the sprite to put on different frames
//Only AnimSprite can run Animation
class Animation: public Action
{
public:
	Animation(VisibleObject* host, int duration);
	static Animation* create(VisibleObject* host, int duration);
	virtual void getCmdQueue() override;
private:
	int frames;
};



//AnimationCommand asks an AnimSprite to put on a frame of a specified index
class AnimationCommand: public Command
{
public:
	AnimationCommand(int aIndex);
	virtual void apply(VisibleObject* vo);
private:
	int index;
};
#endif
