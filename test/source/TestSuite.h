#ifndef _TESTSUITE_H_
#define _TESTSUITE_H_

#include <vector>
#include "TestCase.h"

// A Test Suite tests on a sub-system
class TestSuite
{
public:
	void runThisSuite();
	virtual std::string suiteName() { return "default name"; }
	void addTestCase(TestCase* testcase);
	virtual ~TestSuite();
	std::vector<TestCase*> testCases;
};
#endif
