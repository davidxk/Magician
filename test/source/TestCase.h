#ifndef _TESTS_BASE_TEST_
#define _TESTS_BASE_TEST_

#include <cassert>
#include <iostream>

class TestCase
{
public:
	virtual void run()=0;
	virtual std::string testName() { return "default name"; };
	virtual ~TestCase() { };
};

#endif
