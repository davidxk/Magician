#include "user/Sleep.h"

Sleep::Sleep(VisibleObject* host, int duration): Action(host, duration, false)
{
	getCmdQueue();
}

Sleep* Sleep::create(Action* host, int duration)
{
	return new Sleep(host, duration);
}

void Sleep::getCmdQueue()
{
	int steps = duration/magician::TIME_UNIT;
	for(int i=0; i<=steps; i++)
		cmdQueue.push( Command() );
}
