#ifndef _ACTION_MANAGER_H_
#define _ACTION_MANAGER_H_

#include "action/Action.h"
#include "basic/Singleton.cpp"
#include "display/VisibleObject.h"
#include <list>
#include <mutex>
#include <unordered_map>
#include <vector>
using namespace std;

//Action Manager maintains a list of running actions
//In each update, it executes commands which alters the attributes of objects 
class ActionManager
{
public:
	ActionManager();
	void addAction(Action* action);
	void addAction(Action* action, VisibleObject* host);
	//void removeAction(Action* action);
	//updates sprites' attributes in vManager
	void update();
	void pauseHost(VisibleObject* host);
	void resumeHost(VisibleObject* host);
	~ActionManager();

protected: // For testability
	void verifyAction(Action* action);
	list<Action*> actionList;
	mutex mtx;
};
typedef Singleton<ActionManager> sActionManager;
#define aManager sActionManager::instance()
#endif
