#ifndef _TESTS_BASE_TEST_
#define _TESTS_BASE_TEST_

#include <cassert>

class TestCase
{
public:
	virtual void run()=0;
	virtual ~TestCase() { };
};

#endif
