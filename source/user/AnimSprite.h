#ifndef _ANIM_SPRITE_H_
#define _ANIM_SPRITE_H_

#include "user/Sprite.h"
#include <vector>
#include <string>

class AnimSprite: public Sprite
{
public:
	AnimSprite(const string& fileName);
	static AnimSprite* create(const string& fileName);
	void putOn(int index);
	vector<vector<wstring> > batch;
};
#endif
