#ifndef _ACTION_MANAGER_H_
#define _ACTION_MANAGER_H_

#include "base/Action.h"
#include "base/Singleton.cpp"
#include "base/VisibleObject.h"
#include <list>
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
	void schedule(Action* action, int timepoint);
	void scheduleAfter(Action* action, int period);
	//void removeAction(Action* action);
	//updates sprites' attributes in vManager
	void update();
	void pauseHost(VisibleObject* host);
	void resumeHost(VisibleObject* host);
	~ActionManager();

	list<Action*> actionList;
	unordered_map<int,vector<Action*> > scheduleList;
private:
	void checkSchedule();
	void verifyAction(Action* action);
};
typedef Singleton<ActionManager> sActionManager;
#define aManager sActionManager::instance()
#endif
