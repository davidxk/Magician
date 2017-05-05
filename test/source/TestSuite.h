#ifndef _TESTSUITE_H_
#define _TESTSUITE_H_

#include <vector>
#include "TestCase.h"

// A Test Suite tests on a sub-system
class TestSuite
{
public:
	int runThisSuite();
	virtual std::string suiteName() { return "default name"; }
	int getTestCaseNum();
	void addTestCase(TestCase* testcase);
	virtual ~TestSuite();
private:
	bool runTestProc(TestCase* it);
	std::vector<TestCase*> testCases;
};
#endif
