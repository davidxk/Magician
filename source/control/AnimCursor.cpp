#include "control/AnimCursor.h"

AnimCursor::AnimCursor(const string& fileName): AnimSprite( fileName ) { }

void AnimCursor::respond(Key key)
{
	Direction dirc;
	switch( key )
	{
		case 'a': case 'h':
			dirc = LEFT; break;
		case 's': case 'j':
			dirc = DOWN; break;
		case 'd': case 'l':
			dirc = RIGHT; break;
		case 'w': case 'k':
			dirc = UP; break;
		default: return;
	}
	AnimCursor::move( dirc );
	setDisplayImage( dirc );
}

void AnimCursor::move(Direction dirc)
{
	const Coord coords[]= { Coord::CoordXY(0, -1), Coord::CoordXY(0, 1),
		Coord::CoordXY(-1, 0), Coord::CoordXY(1, 0) };

	Coord currentPosition = getPos();
	currentPosition += coords[ dirc ]; 
	setPos( currentPosition );
	setPos( currentPosition );
}
