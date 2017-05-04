#ifndef _ANIM_SPRITE_TEST_H_
#define _ANIM_SPRITE_TEST_H_

#include "TestCase.h"

//description of the class here
class AnimSpriteTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Anim Sprite Test"; }
private:
	void testCreate();
	void testSetDisplayImage();
};
#endif
