#ifndef _ANIM_CURSOR_H_
#define _ANIM_CURSOR_H_

#include "visible/AnimSprite.h"
#include "control/KeyListener.h"

//description of the class here
class AnimCursor: public KeyListener, public AnimSprite
{
public:
	AnimCursor(const string& fileName);
	void respond(Key key);
};
#endif
