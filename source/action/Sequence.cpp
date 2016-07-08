#include "action/Sequence.h"
#include <cassert>

Sequence::Sequence(Action* action_a, Action* action_b): 
	Action(action_a->host, action_a->duration+action_b->duration)
{
	while( !action_a->cmdQueue.empty() )
	{
		cmdQueue.push( action_a->cmdQueue.front()->clone() );
		action_a->cmdQueue.pop();
	}
	while( !action_b->cmdQueue.empty() )
	{
		cmdQueue.push( action_b->cmdQueue.front()->clone() );
		action_b->cmdQueue.pop();
	}

	delete action_a, action_a = NULL;
	delete action_b, action_b = NULL;
}

Sequence* Sequence::create(Action* action_a, Action* action_b)
{
	assert(action_a && action_b) ;
	return new Sequence(action_a, action_b);
}
