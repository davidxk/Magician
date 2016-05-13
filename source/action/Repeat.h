#ifndef _REPEAT_H_
#define _REPEAT_H_

#include "action/Action.h"

//Both finite and infinite repetition uses this action
class Repeat: public Action
{
public:
	static Repeat* create(Action* action, int aTimes);

	static const int TIMES_FOREVER;
	int times;
	
private:
	Repeat(Action* action, int aTimes);
};
#endif
