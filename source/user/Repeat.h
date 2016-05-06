#ifndef _REPEAT_H_
#define _REPEAT_H_

#include "base/Action.h"

//description of the class here
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
