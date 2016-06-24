#include "action/Sleep.h"
#include "basic/MagicianMacros.h"

Sleep::Sleep(VisibleObject* host, int duration): Action(host, duration)
{
	getCmdQueue();
}

Sleep* Sleep::create(VisibleObject* host, int duration)
{
	return new Sleep(host, duration);
}

void Sleep::getCmdQueue()
{
	int steps = duration/magician::TIME_UNIT;
	for(int i=0; i<=steps; i++)
		cmdQueue.push( new Command() );
}
