#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "action/Action.h"
#include "action/Command.h"
#include "display/Node.h"
#include "basic/Coord.h"

//An Animation action asks the sprite to put on different frames
//Only AnimSprite can run Animation
class Animation: public Action
{
public:
	Animation(Node* host, int duration);
	static Animation* create(Node* host, int duration);
	virtual void getCmdQueue() override;
	void setFrames(int frames);
private:
	int frames;
};



//AnimationCommand asks an AnimSprite to put on a frame of a specified index
class AnimationCommand: public Command
{
public:
	AnimationCommand(int aIndex);
	virtual Command* clone() { return new AnimationCommand(*this); }
	virtual void apply(Node* vo);
private:
	int index;
};
#endif
