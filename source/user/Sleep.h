#ifndef _SLEEP_H_
#define _SLEEP_H_

#include "base/Action.h"
#include "base/VisibleObject.h"

//description of the class here
class Sleep: public Action
{
public:
	Sleep(Action* host, int duration);
	Sleep* create(VisibleObject* host, int duration);
	void getCmdQueue();
};
#endif
