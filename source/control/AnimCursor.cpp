#include "control/AnimCursor.h"

AnimCursor::AnimCursor(const string& fileName): AnimSprite( fileName ) { }

void AnimCursor::respond(Key key)
{
	const int up = 0, down = 1, left = 2, right = 3;
	Coord coords[]= { Coord::CoordXY(0, -1), Coord::CoordXY(0, 1),
		Coord::CoordXY(-1, 0), Coord::CoordXY(1, 0) };

	int index;
	Coord currentPosition = getPos();
	switch( key )
	{
		case 'a': index = left; break;
		case 's': index = down; break;
		case 'd': index = right; break;
		case 'w': index = up; break;
		default: return;
	}
	currentPosition += coords[ index ]; 
	setPos( currentPosition );
	setDisplayImage( index );
}
