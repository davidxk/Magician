#ifndef _ACTION_TEST_H_
#define _ACTION_TEST_H_

#include "TestCase.h"
#include "user/Sprite.h"
#include <iostream>

//description of the class here
class ActionTest: public TestCase
{
public:
	void run();
	virtual std::string testName() override { return "Action Test"; }
private:
	void testMoveTo();
	void testAnimation();
	void testSequence();
	void testRepeat();
	Sprite* sp;
};
#endif
