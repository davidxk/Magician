#ifndef _RPG_CURSOR_HERO_H_
#define _RPG_CURSOR_HERO_H_

#include "Magician.h"
#include <vector>
using namespace std;

//description of the class here
class RPGCursorHero: public Cursor
{
public:
	RPGCursorHero(const string& fileName);
	RPGCursorHero(const Image image);
	void setMap(vector<vector<int> > map, Coord offset);
	virtual void respond(Key key);
protected:
	int mine(const Coord& coord);
	vector<vector<int> > map;
	Coord offset;
};
#endif
