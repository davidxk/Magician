#ifndef _REPEAT_H_
#define _REPEAT_H_

#include "base/Action.h"

//description of the class here
class Repeat: public Action
{
public:
	Repeat(Action* action, int nTimes);
	static Repeat* create(Action* action, int nTimes);
	void count();
	int counter;
};
#endif