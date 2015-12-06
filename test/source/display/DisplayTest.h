#ifndef _DISPLAY_TEST_H_
#define _DISPLAY_TEST_H_

#include "TestCase.h"

//description of the class here
class DisplayTest: public TestCase
{
public:
	virtual void run() override;
private:
	void testSprite();
	void testVManager();
	void testMoveTo();
	void testDisplay();
};
#endif
