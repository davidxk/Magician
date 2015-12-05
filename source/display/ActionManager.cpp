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
		if(action->cmdQueue.empty())
		{
			actionList.remove(action);
			action->host->inAction = false;
			delete action;
		}

		action->cmdQueue.front().apply( action->host );

		if(action->isRepeat) 
			action->cmdQueue.push( action->cmdQueue.front() );
		action->cmdQueue.pop();
	}
}

ActionManager::~ActionManager()
{
	for(auto& action: actionList)
		delete action;
}
