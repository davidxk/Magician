#ifndef _TESTSUITE_H_
#define _TESTSUITE_H_

#include <vector>
#include "TestCase.h"

//description of the class here
class TestSuite
{
public:
	void runThisSuite();
	void addTestCase(TestCase* testcase);
	virtual ~TestSuite();
	std::vector<TestCase*> testCases;
};
#endif
