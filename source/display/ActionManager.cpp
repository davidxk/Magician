#include "ActionManager.h"
#include <cassert>
#include "basic/TimeService.h"

ActionManager::ActionManager() { }

void ActionManager::addAction(Action* action)
{
	verifyAction( action );
	actionList.push_back( action );
	action->host->inAction = true;
}

void ActionManager::schedule(Action* action, int timepoint)
{
	verifyAction( action );
	int cycle = timepoint / TimeService::TIME_UNIT;
	if (scheduleList.find(cycle) != scheduleList.end())
		scheduleList[ cycle ].push_back( action );
	else 
	{
		vector<Action*> tmp;
		tmp.push_back( action );
		scheduleList.emplace( cycle, tmp );
	}
}

void ActionManager::update()
{
	checkSchedule();
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

void ActionManager::checkSchedule()
{
	int cntCycle = TimeService::getCycle();
	if(scheduleList.find(cntCycle) != scheduleList.end())
	{
		for(const auto& action: scheduleList[cntCycle])
			addAction( action );
		scheduleList.erase( cntCycle );
	}
}

void ActionManager::verifyAction(Action* action)
{
	assert( action != NULL );
	assert( action->host != NULL );
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
	for(const auto& action: actionList)
		delete action;

	for(const auto& list: scheduleList)
		for(const auto& action: list.second)
			delete action;
}
