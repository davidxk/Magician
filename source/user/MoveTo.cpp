#include "user/MoveTo.h"
#include "base/Command.h"
#include "basic/MagicianMacros.h"

MoveTo::MoveTo(VisibleObject* host, int duration, Coord aDest, 
		bool isRepeat): Action(host, duration, isRepeat), dest(aDest) 
{ 
	this->from = host->pos;
	getCmdQueue();
}

MoveTo* MoveTo::create(VisibleObject* host, int duration, Coord aDest, bool isRepeat)
{
	return new MoveTo(host, duration, aDest, isRepeat);
}

void MoveTo::getCmdQueue()
{
	//get vector segments from a whole vector
	//(next-from) / (dest-from) = i / (duration / time_unit)
	int steps = duration/magician::TIME_UNIT;
	for(int i=1; i<=steps; i++)
	{
		Coord next = (dest-from) * i / steps + from;
		cmdQueue.push( Command(next) );
	}
}
