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
};
#endif
