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

class Again: public Action
{
public:
	static Again* create(Action* action, int aTimes);

	static const int TIMES_FOREVER;
	int times;
	
private:
	Again(Action* action, int aTimes);
};

class AgainCommand: public Command
{
public:
	AgainCommand(int times, Action* again, Command* last);
	virtual ~AgainCommand() { delete lastCmd; }
	virtual void apply(Node* vo);
	virtual Command* clone() { return new AgainCommand(*this); }
private:
	int cntTimes;
	Action* action;
	Command* lastCmd;
};
#endif
