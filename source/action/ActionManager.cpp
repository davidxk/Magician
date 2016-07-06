#include "action/ActionManager.h"
#include <cassert>
#include "action/Command.h"
#include "basic/MagicianMacros.h"

ActionManager::ActionManager() { }

void ActionManager::addAction(Action* action)
{
	lock_guard<mutex> lock(mtx);
	verifyAction( action );
	actionList.push_back( action );
	action->host->setInAction( true );
}

void ActionManager::update()
{
	lock_guard<mutex> lock(mtx);
	for(auto it = actionList.begin(); it != actionList.end(); it++)
	{
		Action* action = *it;
		if(action->isPause) continue;

		if(action->cmdQueue.empty())
		{
			action->host->setInAction( false );
			delete action;
			actionList.erase( it );
			action = NULL;
			continue;
		}

		applyTree( action->host, action );

		if(action->isRepeat) 
			action->cmdQueue.push( action->cmdQueue.front() );
		// Figure out a way if memory leaks
		//else delete action->cmdQueue.front();
		action->cmdQueue.pop();
	}
}

void ActionManager::applyTree(Node* node, Action* action)
{
	for(auto& child: node->getChildren())
		applyTree( child, action );
	action->cmdQueue.front()->apply( node );
}

void ActionManager::verifyAction(Action* action)
{
	assert( action != NULL );
	assert( action->host != NULL );
}



void ActionManager::pauseHost(Node* host)
{
	lock_guard<mutex> lock(mtx);
	for(auto& action: actionList)
		if( action->host == host )
			action->isPause = true;
}

void ActionManager::resumeHost(Node* host)
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
