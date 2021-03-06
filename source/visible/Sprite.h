#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "display/Node.h"

//A Sprite is a Visible Object that's initialized with an image
class Sprite: public Node
{
public:
	static Sprite* create(const string& fileName);
	static Sprite* create(const Image image);
	Sprite() { }
protected:
	Sprite(const string& fileName);
	Sprite(const Image image);
};
#endif
