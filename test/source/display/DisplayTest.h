#ifndef _DISPLAY_TEST_H_
#define _DISPLAY_TEST_H_

#include "TestCase.h"
#include <iostream>

//description of the class here
class DisplayTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Display Test"; }
	~DisplayTest();
private:
	void testSprite();
	void testVManager();
	void testDisplay();
};
#endif
