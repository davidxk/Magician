#include "action/Animation.h"
#include <cassert>
#include "basic/TimeService.h"
#include "visible/AnimSprite.h"

Animation::Animation(Node* host, int duration):
	Action(host, duration)
{ 
	AnimSprite* as = (AnimSprite*) host;
	frames = as->batch.size();
	getCmdQueue();
}

Animation* Animation::create(Node* host, int duration)
{
	return new Animation(host, duration);
}

void Animation::getCmdQueue()
{
	int steps = duration/TimeService::TIME_UNIT;
	assert( steps > frames );

	int cycle = steps / frames;
	for(int i=0; i<steps; i++)
	{
		if( i/cycle == frames ) break;
		if( i % cycle == 0 )
			cmdQueue.push( new AnimationCommand( i/cycle ) );
		else 
			cmdQueue.push( new Command() );
	}
}

void Animation::setFrames(int frames)
{
	this->frames = frames;
}



//AnimationCommand
AnimationCommand::AnimationCommand(int aIndex): index(aIndex) { }

void AnimationCommand::apply(Node* vo)
{
	//assert vo is AnimSprite* type
	AnimSprite* as = (AnimSprite*) vo;
	as->setDisplayImage( index );
}
