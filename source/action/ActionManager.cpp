#include "ActionManager.h"
#include <cassert>

ActionManager::ActionManager() { }

void ActionManager::addAction(Action* action)
{
	lock_guard<mutex> lock(mtx);
	verifyAction( action );
	actionList.push_back( action );
	action->host->inAction = true;
}

void ActionManager::update()
{
	lock_guard<mutex> lock(mtx);
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

void ActionManager::verifyAction(Action* action)
{
	assert( action != NULL );
	assert( action->host != NULL );
}



void ActionManager::pauseHost(VisibleObject* host)
{
	lock_guard<mutex> lock(mtx);
	for(auto& action: actionList)
		if( action->host == host )
			action->isPause = true;
}

void ActionManager::resumeHost(VisibleObject* host)
{
	lock_guard<mutex> lock(mtx);
	for(auto& action: actionList)
		if( action->host == host )
			action->isPause = false;
}

ActionManager::~ActionManager()
{
	for(const auto& action: actionList)
		delete action;
}
