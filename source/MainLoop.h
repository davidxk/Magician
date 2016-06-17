#ifndef _MAIN_LOOP_H_
#define _MAIN_LOOP_H_

#include "display/DisplayCentral.h"

class MainLoop
{
public:
	MainLoop();
	void runWithScene(Scene* scene);
	void replaceScene(Scene* scene);
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
#endif
