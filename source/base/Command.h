#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "base/VisibleObject.h"
#include "basic/Coord.h"

//A Command is a time-unit size Action slice
//Action is implemented a series of commands that alter the objects' attributes
class Command
{
public:
	//Should more type emerge, use polymorphic behaviour instead of switch case
	enum CmdType { CHANGE_POS, CHANGE_IMG, SLEEP, VANISH, APPEAR };
	CmdType type;
	Coord pos; 
	int index; 
public:
	Command();
	Command(CmdType aType);
	Command(Coord pos);
	Command(int index);
	void apply(VisibleObject* vo);
};
#endif
