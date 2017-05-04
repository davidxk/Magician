#ifndef _SPRITE_TEST_H_
#define _SPRITE_TEST_H_

#include "TestCase.h"

//description of the class here
class SpriteTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Sprite Test"; }
private:
	void testCreate();
};
#endif
