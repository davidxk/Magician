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
	bool isPause;
	std::queue<Command> cmdQueue;

	//static Action* create(VisibleObject* aHost, int dur, bool isRep = false) 
	Action(VisibleObject* aHost, int aDuration, bool aIsRepeat = false);
	//Called within constructor
	virtual void getCmdQueue() { };
	void pause();
	void resume();
	void stop();
	virtual void setHost(VisibleObject* host);
	//virtual ~Action() { }
};
#endif
