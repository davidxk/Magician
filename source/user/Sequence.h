#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include "base/Action.h"

//Sequence action is implemented as the concatenation of command queues
//Initiating a Sequence from an array of actions is yet to be implemented
class Sequence: public Action
{
public:
	static Sequence* create(Action* action_a, Action* action_b);

private:
	Sequence(Action* action_a, Action* action_b);
};
#endif
