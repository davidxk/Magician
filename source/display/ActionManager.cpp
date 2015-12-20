#include "ActionManager.h"
#include <cassert>

void ActionManager::addAction(Action* action)
{
	assert( action != NULL );
	assert( action->host != NULL );
	actionList.push_back( action );
	action->host->inAction = true;
}

void ActionManager::addAction(Action* action, VisibleObject* host)
{
	assert( action != NULL );
	assert( host != NULL );
	action->setHost( host );
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





void ActionManager::pauseHost(VisibleObject* host)
{
	for(auto& action: actionList)
		if( action->host == host )
			action->isPause = true;
}

void ActionManager::resumeHost(VisibleObject* host)
{
	for(auto& action: actionList)
		if( action->host == host )
			action->isPause = false;
}

ActionManager::~ActionManager()
{
	for(auto& action: actionList)
		delete action;
}
