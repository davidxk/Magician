#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include "base/Action.h"

//description of the class here
class Sequence: public Action
{
public:
	Sequence(Action* action_a, Action* action_b);
	static Sequence* create(Action* action_a, Action* action_b);
};
#endif
