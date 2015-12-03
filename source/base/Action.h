#ifndef _ACTION_H_
#define _ACTION_H_

#include "base/Command.h"
#include "base/VisibleObject.h"
#include <queue>

class Action
{
public:
	VisibleObject* host;
	int duration;
	bool isRepeat;
	std::queue<Command> cmdQueue;

	//static Action* create(VisibleObject* aHost, int dur, bool isRep = false) 
	Action(VisibleObject* aHost, int aDuration, bool aIsRepeat = false);
private:
	//Called within constructor
	virtual void getCmdQueue() { };
};
#endif
