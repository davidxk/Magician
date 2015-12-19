#include "user/Repeat.h"
#include <cassert>

Repeat::Repeat(Action* action, int nTimes):
	Action(action->host, action->duration * nTimes, false)
{
	for(int i=0; i<nTimes; i++)
		for(const auto& it: action->cmdQueue)
			cmdQueue.push( it );

	delete action, action = NULL;
}

Repeat* Repeat::create(Action* action, int nTimes)
{
	assert( action != NULL );
	return new Repeat(action, nTimes);
}
