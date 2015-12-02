
#include "Command.h"
#include "VisibleObject.h"
#include <queue>

class Action
{
public:
	VisibleObject* host;
	int duration;
	bool isRepeat;
	queue<Command> cmdQueue;

	virtual Action& create();
private:
	Action(VisibleObject* aHost, int aDuration, bool aIsRepeat = false);
	//Called within constructor
	virtual getCmdQueue();
};
