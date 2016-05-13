#ifndef _SLEEP_H_
#define _SLEEP_H_

#include "action/Action.h"
#include "display/VisibleObject.h"

//A Sleep action defines a period for doing nothing
//Sleep action does not block any thread
class Sleep: public Action
{
public:
	Sleep(VisibleObject* host, int duration);
	static Sleep* create(VisibleObject* host, int duration);
	void getCmdQueue();
};
#endif
