#ifndef _ACTION_MANAGER_H_
#define _ACTION_MANAGER_H_

#include "base/Action.h"
#include "base/Singleton.cpp"
#include <list>

//Action Manager can be globally accessed
class ActionManager
{
public:
	list<Action*> actionList;
	void addAction(Action* action);
	//void removeAction(Action* action);
	//updates sprites' attributes in vManager
	void update();
};
typedef Singleton<ActionManager> sActionManager;
#define aManager sActionManager::instance()
#endif
