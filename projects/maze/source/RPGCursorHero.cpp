#include "RPGCursorHero.h"

RPGCursorHero::RPGCursorHero(const string& fileName): Cursor( fileName ) { }

RPGCursorHero::RPGCursorHero(const Image image): Cursor( image ) { }

void RPGCursorHero::setMap(vector<vector<int> > map, Coord offset)
{
	this->map = map;
	this->offset = offset;
}

int RPGCursorHero::mine(const Coord& coord)
{
	Coord pos = coord - offset;
	if(pos.line < 0 || pos.column < 0)
		return 0;
	return map[pos.line][pos.column];
}

void RPGCursorHero::respond(Key key)
{
	Coord nextPosition = getNextPosition( getDirection( key ) );
	if( mine( nextPosition ) == 0 )
		setPos( nextPosition );
}
