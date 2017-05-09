#include "control/Cursor.h"

Cursor::Cursor(const string& fileName): Sprite( fileName ) { }

Cursor::Cursor(const Image image): Sprite( image ) { }

void Cursor::respond(Key key)
{
	const Coord VEC_LEFT = Coord::CoordXY(-1, 0); 
	const Coord VEC_RIGHT = Coord::CoordXY(1, 0); 
	const Coord VEC_UP = Coord::CoordXY(0, -1); 
	const Coord VEC_DOWN = Coord::CoordXY(0, 1); 
	Coord currentPosition = getPos();
	switch( key )
	{
		case 'a': case 'h':
			currentPosition += VEC_LEFT; break;
		case 's': case 'j':
			currentPosition += VEC_DOWN; break;
		case 'd': case 'l':
			currentPosition += VEC_RIGHT; break;
		case 'w': case 'k':
			currentPosition += VEC_UP; break;
	}
	setPos( currentPosition );
}
