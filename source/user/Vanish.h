#ifndef _VANISH_H_
#define _VANISH_H_

#include "base/Action.h"

//description of the class here
class Vanish: public Action
{
public:
	Vanish(VisibleObject* host);
	static Vanish* create(VisibleObject* host);
	void getCmdQueue();
};
#endif
