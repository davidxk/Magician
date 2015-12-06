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
	for(auto& action: actionList)
	{
		if(action->isPause) continue;

		if(action->cmdQueue.empty())
		{
			action->host->inAction = false;
			delete action;
			action = NULL;
			continue;
		}

		action->cmdQueue.front().apply( action->host );

		if(action->isRepeat) 
			action->cmdQueue.push( action->cmdQueue.front() );
		action->cmdQueue.pop();
	}
	actionList.remove(NULL);
}

ActionManager::~ActionManager()
{
	for(auto& action: actionList)
		delete action;
}
