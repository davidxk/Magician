#ifndef _TEST_TESTROOT_H_
#define _TEST_TESTROOT_H_

#include <vector>
#include "TestSuite.h"

//description of the class here
class TestRoot
{
public:
	TestRoot();
	void runAll();
	~TestRoot();
	std::vector<TestSuite*> testSuites;
};
#endif
