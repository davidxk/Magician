#include "base/Command.h"

Command::Command(): type(SLEEP) { }

Command::Command(Coord aPos):
	type(CHANGE_POS), pos(aPos) { }
	
Command::Command(int aIndex):
	type(CHANGE_IMG), index(aIndex) { }

void Command::apply(VisibleObject* vo)
{
	switch(type)
	{
		case CHANGE_POS:
			vo->setPos( pos );
			break;
		case CHANGE_IMG:
			//assert vo is AnimSprite* type
			//AnimSprite* as = (AnimSprite* vo);
			//as->putOn( index );
			break;
		case SLEEP:
			break;
		default:
			//cout<<"not yet supported";
			break;
	}
}
