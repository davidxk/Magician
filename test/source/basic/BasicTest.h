#ifndef _BASIC_TEST_H_
#define _BASIC_TEST_H_

#include "TestCase.h"
#include <iostream>

class BasicTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Basic Test"; }
private:
	void testSize();
	void testCoord();
	void testImageLoader();
};
#endif
