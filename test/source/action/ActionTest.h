#ifndef _ACTION_TEST_H_
#define _ACTION_TEST_H_

#include "TestCase.h"
#include "visible/Sprite.h"
#include <iostream>

//description of the class here
class ActionTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Action Test"; }
private:
	void testConstructor();
	void testClone();
	void testMoveTo();
	void testMoveBy();
	void testAnimation();
	void testSequence();
	void testRepeat();
	Sprite* sp;
};
#endif
