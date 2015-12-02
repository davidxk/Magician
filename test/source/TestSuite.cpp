#include "TestSuite.h"

void TestSuite::runThisSuite()
{
	for(const auto& it: testCases)
		it->run();
}

void TestSuite::addTestCase(TestCase* testcase)
{
	testCases.push_back(testcase);
}

TestSuite::~TestSuite()
{
	for(auto& it: testCases)
		delete it;
}
