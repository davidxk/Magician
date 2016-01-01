#ifndef _BASE_TEST_H_
#define _BASE_TEST_H_

#include "TestCase.h"
#include <iostream>

//description of the class here
class BaseTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Base Test"; }
};
#endif
