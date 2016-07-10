#include "action/Repeat.h"
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
	times = aTimes;

	if(times == TIMES_FOREVER)
		this->isRepeat = true, aTimes = 1;

	//add function here perhaps
	for(int i=0; i<aTimes; i++)
	{
		queue<Command*> tmp = action->cmdQueue;
		while( !tmp.empty() )
		{
			cmdQueue.push( tmp.front()->clone() );
			tmp.pop();
		}
	}

	delete action, action = NULL;
}




const int Again::TIMES_FOREVER = 0;

Again* Again::create(Action* action, int aTimes)
{
	assert( action != NULL );
	return new Again(action, aTimes);
}

Again::Again(Action* action, int aTimes):
	Action(action->host, action->duration * aTimes, true)
{
	if(aTimes == TIMES_FOREVER)
	{
		this->isRepeat = true;
		while( !action->cmdQueue.empty() )
		{
			cmdQueue.push( action->cmdQueue.front() );
			action->cmdQueue.pop();
		}
		delete action, action = NULL;
		return;
	}

	times = aTimes;
	//add function here perhaps
	queue<Command*>& que = action->cmdQueue;
	cmdQueue.push( new AgainCommand( times, this, que.front() ) );
	que.pop();
	while( !que.empty() )
	{
		cmdQueue.push( que.front() );
		que.pop();
	}

	delete action, action = NULL;
}




// Again Command
AgainCommand::AgainCommand(int times, Action* again, Command* last): 
	cntTimes( times ), action( again ), lastCmd( last ) { }

void AgainCommand::apply(Node* node)
{
	lastCmd->apply( node );
	if(cntTimes > 1)
		cntTimes--;
	else
		action->isRepeat = false;
}
