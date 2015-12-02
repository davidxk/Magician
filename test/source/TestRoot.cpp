#include "TestRoot.h"

#include "basic/BasicSuite.h"

TestRoot::TestRoot()
{
	testSuites.push_back(new BasicSuite);
}

void TestRoot::runAll()
{
	for(const auto& it: testSuites)
		it->runThisSuite();
}

TestRoot::~TestRoot()
{
	for(auto it: testSuites)
		delete it;
}
