#include "base/Command.h"

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
			//AnimSprite* as = (AnimSprite* vo);
			//as->putOn( index );
			break;
		default:
			//cout<<"not yet supported";
			break;
	}
}
