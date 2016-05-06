#include "user/Animation.h"
#include <cassert>
#include "basic/MagicianMacros.h"
#include "user/AnimSprite.h"

Animation::Animation(VisibleObject* host, int duration, bool isRepeat):
	Action(host, duration, isRepeat)
{ 
	AnimSprite* as = (AnimSprite*) host;
	frames = as->batch.size();
	getCmdQueue();
}

Animation* Animation::create(VisibleObject* host, int duration, bool isRepeat)
{
	return new Animation(host, duration, isRepeat);
}

void Animation::getCmdQueue()
{
	int steps = duration/magician::TIME_UNIT;
	assert( steps > frames );

	int cycle = steps / frames;
	for(int i=0; i<steps; i++)
	{
		if( i/cycle == frames ) break;
		if( i % cycle == 0 )
			cmdQueue.push( AnimationCommand( i/cycle ) );
		else 
			cmdQueue.push( Command() );
	}
}




//AnimationCommand
AnimationCommand::AnimationCommand(int aIndex): index(aIndex) { }

void AnimationCommand::apply(VisibleObject* vo)
{
	//assert vo is AnimSprite* type
	AnimSprite* as = (AnimSprite*) vo;
	as->setDisplayImage( index );
}
