#ifndef _ACTION_H_
#define _ACTION_H_

#include "action/Command.h"
#include "basic/Object.h"
#include "display/Node.h"
#include <queue>

//Action is the base class for all actions
//Action base class provides basic services for all actions
class Action: public Object
{
public:
	Node* host;
	int duration;
	bool isRepeat;
	bool isPause;
	std::queue<Command*> cmdQueue;

	Action(Node* aHost, int aDuration, bool aIsRepeat = false);
	virtual Action* clone() const;
	void pause();
	void resume();
	void stop();
	void addToManager();
	void setHost(Node* host);
	virtual void initWithHost(Node* host) { }
	virtual ~Action();
protected:
	//Called within constructor
	virtual void getCmdQueue() { };
};
#endif
