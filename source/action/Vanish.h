#ifndef _VANISH_H_
#define _VANISH_H_

#include "action/Action.h"
#include "action/Command.h"

//Vanish action instantly makes a sprite vanish
class Vanish: public Action
{
public:
	Vanish(Node* host);
	static Vanish* create(Node* host);
	virtual void getCmdQueue() override;
};

//Appear action instantly makes a vinished sprite appear
class Appear: public Action
{
public:
	Appear(Node* host);
	static Appear* create(Node* host);
	virtual void getCmdQueue() override;
};

//Blink action makes sprite blink for cnt times in duration time
class Blink: public Action
{
public:
	Blink(Node* host, int duration, int cnt);
	static Blink* create(Node* host, int duration, int cnt);
	static Blink* create(int dur, int cnt) { return new Blink(NULL, dur, cnt); }
	virtual void getCmdQueue() override;
protected:
	int times;
};


class VanishCommand: public Command
{
public:
	virtual void apply(Node* node);
	virtual Command* clone() { return new VanishCommand(*this); }
};

class AppearCommand: public Command
{
public:
	virtual void apply(Node* node);
	virtual Command* clone() { return new AppearCommand(*this); }
};
#endif
