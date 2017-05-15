#ifndef _CURSOR_H_
#define _CURSOR_H_

#include "control/KeyListener.h"
#include "visible/Sprite.h"

//description of the class here
class Cursor: public KeyListener, public Sprite
{
public:
	Cursor(const string& fileName);
	Cursor(const Image image);
	void respond(Key key);
protected:
	enum Direction { NONE = -1, UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };
	Direction getDirection(Key key);
	Coord getNextPosition(Direction dirc);
};
#endif
