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

	DisplayCentral dc;
private:
	void checkMsg();
	bool exit;
};
#endif
