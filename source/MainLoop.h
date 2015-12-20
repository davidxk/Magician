#ifndef _MAIN_LOOP_H_
#define _MAIN_LOOP_H_

#include "display/DisplayCentral.h"

class MainLoop
{
public:
	MainLoop();
	void readyGo();
	void update();
	~MainLoop();

	static const int TIME_UNIT;
	DisplayCentral dc;
private:
	void checkMsg();
	bool exit;
	bool transitionReady;
};
#endif
