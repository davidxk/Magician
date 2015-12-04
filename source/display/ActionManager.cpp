#include "ActionManager.h"
#include <cassert>

void ActionManager::addAction(Action* action)
{
	assert( action != NULL );
	actionList.push_back( action );
	action->host->inAction = true;
}

void ActionManager::update()
{
	for(const auto& action: actionList)
	{
		action->cmdQueue.front().apply( action->host );

		if(action->isRepeat) 
			action->cmdQueue.push( action->cmdQueue.front() );
		action->cmdQueue.pop();

		if(action->cmdQueue.empty())
		{
			actionList.remove(action);
			action->host->inAction = false;
		}
	}
}
