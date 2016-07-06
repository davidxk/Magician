#include "action/MoveBy.h"
#include <cassert>
#include "action/Command.h"
#include "basic/TimeService.h"

MoveBy::MoveBy(Node* host, int duration, Coord aVect):
	Action(host, duration), vect(aVect)
{
	getCmdQueue();
}

Action* MoveBy::clone() const
{
	return new MoveBy(*this);
}

MoveBy* MoveBy::create(Node* host, int duration, Coord aVect)
{
	return new MoveBy(host, duration, aVect);
}

MoveBy* MoveBy::create(int duration, Coord aVect)
{
	return new MoveBy(NULL, duration, aVect);
}

void MoveBy::getCmdQueue()
{
	int steps = duration / TimeService::TIME_UNIT;
	cmdQueue.push( new MoveByCommand( Coord(0, 0) ) );
	Coord prev(0, 0);
	for(int i=1; i<=steps; i++)
	{
		Coord next = vect * i / steps;
		cmdQueue.push( new MoveByCommand(next-prev) );
		prev = next;
	}
}




//MoveByCommand
MoveByCommand::MoveByCommand(Coord aBy): by(aBy) { }

void MoveByCommand::apply(Node* vo)
{
	vo->pos += by;
}
