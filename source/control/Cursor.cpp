#include "control/Cursor.h"

Cursor::Cursor(const string& fileName): Sprite( fileName ) { }

void Cursor::respond(Key key)
{
	const Coord VEC_LEFT = Coord::CoordXY(-1, 0); 
	const Coord VEC_RIGHT = Coord::CoordXY(1, 0); 
	const Coord VEC_UP = Coord::CoordXY(0, -1); 
	const Coord VEC_DOWN = Coord::CoordXY(0, 1); 
	Coord currentPosition = getPos();
	switch( key )
	{
		case 'a': currentPosition += VEC_LEFT; break;
		case 's': currentPosition += VEC_DOWN; break;
		case 'd': currentPosition += VEC_RIGHT; break;
		case 'w': currentPosition += VEC_UP; break;
	}
	setPos( currentPosition );
}
