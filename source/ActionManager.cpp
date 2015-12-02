#include "ActionManager.h"

void ActionManager::update()
{
	for(const auto& action: actionList)
	{
		action.cmdQueue.head().apply( action.host );

		if(action.isRepeat) 
			action.cmdQueue.push( action.cmdQueue.head() );
		action.cmdQueue.pop();

		if(action.cmdQueue.empty())
			actionList.erase(action);
	}
}
