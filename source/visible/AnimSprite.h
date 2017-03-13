#ifndef _ANIM_SPRITE_H_
#define _ANIM_SPRITE_H_

#include "visible/Sprite.h"
#include <vector>
#include "basic/ColoredChar.h"

//Animation Sprite is initialized with a batch of images
//It changes image on the commands of AnimAction
class AnimSprite: public Sprite
{
public:
	static AnimSprite* create(const string& fileName);
	void setDisplayImage(int index);
	virtual void setForeColor(Color foreColor);
	virtual void setBackColor(Color backColor);

	vector<Image> batch;

protected:
	AnimSprite(const string& fileName);
};
#endif
