#include "Command.h"

Command::Command(CmdType aType, delta aNext):
	type(aType), next(aNext) { }

void Command::apply(VisibleObject* vo)
{
	switch(type)
	{
		case CHANGE_POS:
			vo->setPos( next.pos );
			break;
		case CHANGE_IMG:
			AnimSprite* as = (AnimSprite* vo);
			as->putOn( next.index );
			break;
		default:
			//cout<<"not yet supported";
			break;
	}
}
