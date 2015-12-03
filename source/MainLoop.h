#ifndef _MAIN_LOOP_H_
#define _MAIN_LOOP_H_

#include "display/DisplayCentral.h"

class MainLoop
{
public:
	void readyGo();
	void update();
	static const int TIME_UNIT;
	DisplayCentral dc;
};
#endif
