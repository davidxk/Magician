#ifndef _BASIC_TEST_H_
#define _BASIC_TEST_H_

#include "TestCase.h"

class BasicTest: public TestCase
{
public:
	virtual void run();
private:
	void testSize();
	void testCoord();
	void testImageLoader();
};
#endif
