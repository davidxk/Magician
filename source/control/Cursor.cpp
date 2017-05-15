#include "control/Cursor.h"

Cursor::Cursor(const string& fileName): Sprite( fileName ) { }

Cursor::Cursor(const Image image): Sprite( image ) { }

Cursor::Direction Cursor::getDirection(Key key)
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
		default: return NONE;
	}
	return dirc;
}

Coord Cursor::getNextPosition(Direction dirc)
{
	const Coord coords[]= { Coord::CoordXY(0, -1), Coord::CoordXY(0, 1),
		Coord::CoordXY(-1, 0), Coord::CoordXY(1, 0) };

	Coord currentPosition = getPos();
	return currentPosition + coords[ dirc ]; 
}

void Cursor::respond(Key key)
{
	Direction dirc = getDirection( key );
	if(dirc == NONE) return;
	Coord nextPosition = getNextPosition( dirc );
	setPos( nextPosition );
}
