#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "base/VisibleObject.h"

//Sprite is initiated from file by default
class Sprite: public VisibleObject
{
public:
	static Sprite* create(const string& fileName);
	Sprite() { }
private:
	Sprite(const string& fileName);
};
#endif
