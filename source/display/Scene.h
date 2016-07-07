#ifndef _SCENE_H_
#define _SCENE_H_

#include "action/ActionManager.h"
#include "basic/Scheduler.h"
#include "basic/TimeService.h"
#include "control/KeyDispatcher.h"
#include "display/Node.h"
#include "display/NodeManager.h"

//description of the class here
class Scene
{
public:
	Scene();
	virtual void initScene();
	void addChild(Node* node);
	Node* getRoot() const { return root; }
	void pause();
	void resume();

	NodeManager* getNodeManager() { return &nodeManager; }
	ActionManager* getActionManager() { return &actionManager; }
	Scheduler* getScheduler() { return &schduler; }
	TimeService* getTimeService() { return &timeService; }
	KeyDispatcher* getKeyDispatcher() { return &keyDisptcher; }
protected:
	NodeManager nodeManager;
	ActionManager actionManager;
	Scheduler schduler;
	TimeService timeService;
	KeyDispatcher keyDisptcher;

	Node* root;
};
#endif
