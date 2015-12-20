#include "user/Repeat.h"
#include <cassert>

Repeat::Repeat(Action* action, int nTimes):
	Action(action->host, action->duration * nTimes, true)
{
	cmdQueue = action->cmdQueue;
	counter = nTimes;
	//add function here perhaps
	for(int i=1; i<counter; i++)
	{
		queue<Command> tmp = action->cmdQueue;
		while( !tmp.empty() )
		{
			cmdQueue.push( tmp.front() );
			tmp.pop();
		}
	}

	delete action, action = NULL;
}

Repeat* Repeat::create(Action* action, int nTimes)
{
	assert( action != NULL );
	return new Repeat(action, nTimes);
}

void Repeat::count()
{
	if( counter==0 )
		isRepeat = false;
	else counter--; 
}