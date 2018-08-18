#ifndef _CURSOR_H_
#define _CURSOR_H_

#include "control/KeyListener.h"
#include "visible/Sprite.h"

//description of the class here
class Cursor: public KeyListener, public Sprite
{
public:
	static Cursor* create(const string& fileName){return new Cursor(fileName);}
	static Cursor* create(const Image image) { return new Cursor(image); }
	void respond(Key key);
protected:
	Cursor(const string& fileName);
	Cursor(const Image image);
	enum Direction { NONE = -1, UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };
	Direction getDirection(Key key);
	virtual Coord getNextPosition(Direction dirc);
};
#endif
