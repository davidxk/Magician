#include "action/MoveTo.h"
#include "action/MoveBy.h"
#include <cassert>
#include "action/Command.h"
#include "basic/TimeService.h"

MoveTo::MoveTo(Node* host, int duration, Coord aFrom, Coord aDest):
	Action(host, duration), from(aFrom), dest(aDest) 
{ 
	if( host ) getCmdQueue();
}

Action* MoveTo::clone() const
{
	return new MoveTo(*this);
}

MoveTo* MoveTo::create(Node* host, int duration, Coord aDest)
{
	assert( host );
	return new MoveTo(host, duration, host->getPos(), aDest);
}

MoveTo* MoveTo::create(int duration, Coord aFrom, Coord aDest)
{
	return new MoveTo(NULL, duration, aFrom, aDest);
}

void MoveTo::initWithHost(Node* host)
{
	assert( host );
	this->from = host->getPos();
	while( !cmdQueue.empty() ) cmdQueue.pop();
	getCmdQueue();
}

void MoveTo::getCmdQueue()
{
	//get vector segments from a whole vector
	//(next-from) / (dest-from) = i / (duration / time_unit)
	int steps = duration / TimeService::TIME_UNIT;
	cmdQueue.push( new MoveToCommand(from) );
	Coord prev = from;
	for(int i=1; i<=steps; i++)
	{
		Coord next = (dest-from) * i / steps + from;
		cmdQueue.push( new MoveByCommand( next-prev ) );
		prev = next;
	}
}




//MoveToCommand
MoveToCommand::MoveToCommand(Coord aPos): pos(aPos) { }

void MoveToCommand::apply(Node* node)
{
	node->setPos( pos );
}
