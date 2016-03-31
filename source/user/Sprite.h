#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "base/VisibleObject.h"

//A Sprite is a Visible Object that's initialized with an image
class Sprite: public VisibleObject
{
public:
	static Sprite* create(const string& fileName);
	Sprite() { }
private:
	Sprite(const string& fileName);
};
#endif
