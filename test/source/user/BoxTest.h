#ifndef _BOX_TEST_H_
#define _BOX_TEST_H_

#include "TestCase.h"
#include <iostream>

//description of the class here
class BoxTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Box Test"; }
private:
	void testDiaBox();
	void testTextField();
};
#endif
