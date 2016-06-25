#ifndef _MAIN_LOOP_H_
#define _MAIN_LOOP_H_

#include "basic/Singleton.cpp"
#include "control/KeyDispatcher.h"
#include "display/DisplayCentral.h"
#include "display/Scene.h"

class MainLoop
{
public:
	MainLoop();
	void runWithScene(Scene* scene);
	void replaceScene(Scene* scene);
	void cleanupScene(Scene* scene);
	void end();
	~MainLoop();
	void loopScene(); // For testing

	KeyDispatcher* getKeyDispatcher() { return &kd; }
private:
	void update();
	void checkMsg();
	Scene* runningScene;
	Scene* nextScene;
	bool exitScene;

	DisplayCentral dc;
	KeyDispatcher kd;
};
typedef Singleton<MainLoop> sMainLoop;
#define gMainLoop sMainLoop::instance()
#endif
