#include "TestSuite.h"
#include <iostream>

void TestSuite::runThisSuite()
{
	for(const auto& it: testCases)
	{
		it->run();
		std::cout<<"Finish running case: "<<it->testName()<<std::endl;
	}
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
