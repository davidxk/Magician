#ifndef _ACTION_H_
#define _ACTION_H_

#include "action/Command.h"
#include "display/VisibleObject.h"
#include <queue>

//Action is the base class for all actions
//Action base class provides basic services for all actions
class Action
{
public:
	VisibleObject* host;
	int duration;
	bool isRepeat;
	bool isPause;
	std::queue<Command> cmdQueue;

	Action(VisibleObject* aHost, int aDuration, bool aIsRepeat = false);
	virtual Action* clone() const { return NULL; };
	void pause();
	void resume();
	void stop();
	void addToManager();
	void setHost(VisibleObject* host);
	virtual void initWithHost(VisibleObject* host) { }
	//virtual ~Action() { }
protected:
	//Called within constructor
	virtual void getCmdQueue() { };
};
#endif
