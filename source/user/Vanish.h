#ifndef _VANISH_H_
#define _VANISH_H_

#include "base/Action.h"
#include "base/Command.h"

//Vanish action instantly makes a sprite vanish
class Vanish: public Action
{
public:
	Vanish(VisibleObject* host);
	static Vanish* create(VisibleObject* host);
	void getCmdQueue();
};

//Appear action instantly makes a vinished sprite appear
class Appear: public Action
{
public:
	Appear(VisibleObject* host);
	static Appear* create(VisibleObject* host);
	void getCmdQueue();
};



class VanishCommand: public Command
{
public:
	virtual void apply(VisibleObject* vo);
};

class AppearCommand: public Command
{
public:
	virtual void apply(VisibleObject* vo);
};
#endif
