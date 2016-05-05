#include "user/MoveBy.h"
#include <cassert>
#include "base/Command.h"
#include "basic/TimeService.h"

MoveBy::MoveBy(VisibleObject* host, int duration, Coord aVect, bool isRepeat):
	Action(host, duration, isRepeat), vect(aVect)
{
	getCmdQueue();
}

MoveBy* MoveBy::clone() const
{
	return new MoveBy(*this);
}

MoveBy* MoveBy::create(VisibleObject* host, int duration, Coord aVect, bool isRepeat)
{
	return new MoveBy(host, duration, aVect, isRepeat);
}

MoveBy* MoveBy::create(int duration, Coord aVect, bool isRepeat)
{
	return new MoveBy(NULL, duration, aVect, isRepeat);
}

void MoveBy::getCmdQueue()
{
	int steps = duration / TimeService::TIME_UNIT;
	cmdQueue.push( MoveByCommand( Coord(0, 0) ) );
	Coord prev(0, 0);
	for(int i=1; i<=steps; i++)
	{
		Coord next = vect * i / steps;
		cmdQueue.push( MoveByCommand(next-prev) );
		prev = next;
	}
}




//MoveByCommand
MoveByCommand::MoveByCommand(Coord aBy): by(aBy) { }

void MoveByCommand::apply(VisibleObject* vo)
{
	vo->pos += by;
}
