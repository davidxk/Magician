#ifndef _SLEEP_H_
#define _SLEEP_H_

#include "action/Action.h"
#include "display/Node.h"

//A Sleep action defines a period for doing nothing
//Sleep action does not block any thread
class Sleep: public Action
{
public:
	Sleep(Node* host, int duration);
	static Sleep* create(Node* host, int duration);
	void getCmdQueue();
};

class Wait: public Action
{
public:
	Wait(Node* host, int duration);
	static Wait* create(Node* host, int duration);
	void getCmdQueue();
};

class WaitCommand: public Command
{
public:
	WaitCommand(int cycles, Action* wait);
	virtual void apply(Node* node);
	virtual Command* clone() { return new WaitCommand(*this); }
private:
	int cntCycle;
	Action* action;
};
#endif
