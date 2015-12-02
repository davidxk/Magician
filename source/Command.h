
#include "VisibleObject.h"

class Command
{
public:
	enum CmdType { CHANGE_POS, CHANGE_IMG };
	CmdType type;
	union delta{ Coord pos; int index; } next;
public:
	Command(CmdType aType, delta aNext);
	void apply(VisibleObject* vo);
};
