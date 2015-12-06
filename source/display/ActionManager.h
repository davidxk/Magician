#ifndef _ACTION_MANAGER_H_
#define _ACTION_MANAGER_H_

#include "base/Action.h"
#include "base/Singleton.cpp"
#include <list>

//Action Manager maintains a list of running actions
//In each update, it executes commands which alters the attributes of objects 
class ActionManager
{
public:
	list<Action*> actionList;
	void addAction(Action* action);
	//void removeAction(Action* action);
	//updates sprites' attributes in vManager
	void update();
	~ActionManager();
};
typedef Singleton<ActionManager> sActionManager;
#define aManager sActionManager::instance()
#endif
