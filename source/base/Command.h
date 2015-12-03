#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "base/VisibleObject.h"
#include "basic/Coord.h"

class Command
{
public:
	enum CmdType { CHANGE_POS, CHANGE_IMG };
	CmdType type;
	Coord pos; 
	int index; 
public:
	Command(Coord pos);
	Command(int index);
	void apply(VisibleObject* vo);
};
#endif
