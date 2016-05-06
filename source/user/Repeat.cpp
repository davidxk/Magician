#include "user/Repeat.h"
#include <cassert>

const int Repeat::TIMES_FOREVER = 0;

Repeat* Repeat::create(Action* action, int aTimes)
{
	assert( action != NULL );
	return new Repeat(action, aTimes);
}




Repeat::Repeat(Action* action, int aTimes):
	Action(action->host, action->duration * aTimes)
{
	if(times == TIMES_FOREVER)
		this->isRepeat = true;

	cmdQueue = action->cmdQueue;
	times = aTimes;
	//add function here perhaps
	for(int i=1; i<aTimes; i++)
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
