#ifndef _ANIM_CURSOR_H_
#define _ANIM_CURSOR_H_

#include "visible/AnimSprite.h"
#include "control/KeyListener.h"

//description of the class here
class AnimCursor: public KeyListener, public AnimSprite
{
public:
	AnimCursor(const string& fileName);
	static AnimCursor* create(const string& fileName);
	void respond(Key key);
	enum Direction { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };
	virtual void move(Direction dirc);
};
#endif
