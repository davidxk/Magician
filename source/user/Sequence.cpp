#include "user/Sequence.h"
#include <cassert>

Sequence::Sequence(Action* action_a, Action* action_b): 
	Action(action_a->host, action_a->duration+action_b->duration, false)
{
	cmdQueue = action_a->cmdQueue;
	while( !action_b->empty() )
	{
		cmdQueue.push( action_b->front() );
		action_b.pop();
	}

	delete action_a, action_a = NULL;
	delete action_b, action_b = NULL;
}

Sequence* Sequence::create(Action* action_a, Action* action_b)
{
	assert(action_a && action_b) ;
	assert(action_a->cmdQueue && action_b->cmdQueue);
	return new Sequence(action_a, action_b);
}
