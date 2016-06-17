#ifndef _MAIN_LOOP_H_
#define _MAIN_LOOP_H_

#include "basic/Singleton.cpp"
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

	DisplayCentral dc;
private:
	void loopScene();
	void update();
	void checkMsg();
	Scene* runningScene;
	Scene* nextScene;
	bool exitScene;
};
typedef Singleton<MainLoop> sMainLoop;
#define gMainLoop sMainLoop::instance()
#endif
