#include "base/Command.h"
#include "user/AnimSprite.h"

Command::Command(): type(SLEEP) { }

Command::Command(CmdType aType): 
	type(aType) { }

Command::Command(Coord aPos, CmdType aType): 
	type(aType), pos(aPos)  { }
	
Command::Command(int aIndex):
	type(CHANGE_IMG), index(aIndex) { }

void Command::apply(VisibleObject* vo)
{
	switch(type)
	{
		case MOVE_TO:
			vo->setPos( pos );
			break;
		case MOVE_BY:
			vo->pos += pos ;
			break;
		case CHANGE_IMG:
			//assert vo is AnimSprite* type
			{
				AnimSprite* as = (AnimSprite*) vo;
				as->putOn( index );
			}
			break;
		case SLEEP:
			break;
		case VANISH:
			vo->isVisible = false;
			break;
		case APPEAR:
			vo->isVisible = true;
			break;
		default:
			//cout<<"not yet supported";
			break;
	}
}
