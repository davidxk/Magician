#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

#include <stack>
#include "basic/Singleton.h"
#include "display/DisplayCentral.h"
#include "display/Scene.h"

//description of the class here
class Director
{
public:
	void runWithScene(Scene* scene) { pushScene( scene ); }
	void pushScene(Scene* scene);
	void popScene();
	void replaceScene(Scene* scene);

	NodeManager* getNodeManager() const {
		return sceneStack.top()->getNodeManager(); }
	ActionManager* getActionManager() const {
		return sceneStack.top()->getActionManager(); }
	Scheduler* getScheduler() const {
		return sceneStack.top()->getScheduler(); }
	TimeService* getTimeService() const {
		return sceneStack.top()->getTimeService(); }
	KeyDispatcher* getKeyDispatcher() const {
		return sceneStack.top()->getKeyDispatcher(); }
protected:
	void loopTopScene();
	void cleanupTopScene();
	void mainloop();
	void update();

	bool exitScene;
	DisplayCentral dc;
	stack<Scene*> sceneStack;
};
typedef Singleton<Director> sDirector;
#define gDirector sDirector::instance()
#define gMainLoop gDirector
#define vManager this
#define addObject addChild
#define aManager gDirector->getActionManager()
#define gScheduler gDirector->getScheduler()
#endif
