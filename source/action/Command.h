#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "display/Node.h"
#include "basic/Coord.h"

//A Command is a time-unit size Action slice
//Action is implemented a series of commands that alter the objects' attributes
class Command
{
public:
	Command() { }
	virtual Command* clone() { return new Command(*this); }
	virtual void apply(Node* vo);
};
#endif
