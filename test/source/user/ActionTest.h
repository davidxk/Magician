#ifndef _ACTION_TEST_H_
#define _ACTION_TEST_H_

#include "TestCase.h"
#include "user/Sprite.h"

//description of the class here
class ActionTest: public TestCase
{
public:
	void run();
private:
	void testMoveTo();
	void testAnimation();
	void testSequence();
	void testRepeat();
	Sprite* sp;
};
#endif
